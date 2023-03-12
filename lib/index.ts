import {c_include, generateStreamWriteFunctions, generateType_c, generateTypeReadFunctions, save_c} from "./c/index.js";
import {generateType_ts, save_ts} from "./ts/index.js";
import {collectTypes, Type} from "./common.js";
import {atlas_info} from "./atlas.js";
import {join} from "node:path";
import {mkdirSync} from "node:fs";
import {toCamelCase} from "./c/naming.js";
import {model3d} from "./model3d.js";
import {sg_file, sg_filter, sg_keyframe_transform, sg_node_data, sg_scene_info, sg_text_layer} from "./scenex.js";

c_include("ek/math.h", true, false);
c_include("ek/hash.h", true, false);
c_include("ek/buf.h", false, false);

interface GenerateOptions {
    outputDirC?: string;
    outputDirTs?: string;
    name: string;
    types: Type[];
}

const generate = (options: GenerateOptions) => {
    const types = new Set<Type>();
    collectTypes(types, ...options.types);
    const rtypes = [...types.values()].reverse();
    for (const type of rtypes) {
        generateType_ts(type);
        generateType_c(type);
        generateTypeReadFunctions(type);
        generateStreamWriteFunctions(type);
    }

    const file_prefix = "gen_";
    if (options.outputDirC) {
        try {
            mkdirSync(options.outputDirC, {recursive: true});
        } catch {
        }
        save_c(options.name, join(options.outputDirC, file_prefix + toCamelCase(options.name) + ".h"));
    }

    if (options.outputDirTs) {
        try {
            mkdirSync(options.outputDirTs, {recursive: true});
        } catch {
        }
        save_ts(options.name, join(options.outputDirTs, file_prefix + toCamelCase(options.name) + ".ts"));
    }
};

generate({
    outputDirC: "src",
    outputDirTs: "lib/examples",
    name: "sg",
    types: [
        atlas_info,
        model3d,
        // scenex
        sg_filter,
        sg_node_data,
        sg_file,
    ]
});