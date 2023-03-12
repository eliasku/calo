const includeString = (include: {user?: boolean, api?: boolean, path: string}) =>  {
    if(include.user) {
        return `#include "${include.path}"`;
    }
    return `#include <${include.path}>`;
}

export const printCFile = (decl: {
    name: string,
    includes: {user?: boolean, api?: boolean, path: string}[],
    types: string,
    publicDeclarations: string,
    privateDeclarations: string,
    implementation: string,
}) => {
    const HEADER_GUARD_H = `CALO_GEN_${decl.name.toUpperCase()}_H`;
    const HEADER_IMPLEMENTATION = `CALO_GEN_${decl.name.toUpperCase()}_IMPLEMENTATION`;
    const HEADER_IMPLEMENTED = `CALO_GEN_${decl.name.toUpperCase()}_IMPLEMENTED`;
    return `#ifndef ${HEADER_GUARD_H}
#define ${HEADER_GUARD_H}

#include <stdint.h>
#include <stdbool.h>

${decl.includes.filter(x=>!!x.api).map(includeString).join("\n")}

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*** types ***/

${decl.types}

/*** functions ***/

${decl.publicDeclarations}

// functions

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ${HEADER_GUARD_H}

/*** implementation ***/

#ifdef ${HEADER_IMPLEMENTATION}
#ifdef ${HEADER_IMPLEMENTED}
#error implementation should be included only once
#else
#define ${HEADER_IMPLEMENTED}
#endif // ${HEADER_IMPLEMENTED}

${decl.includes.filter(x=>!x.api).map(includeString).join("\n")}

${decl.privateDeclarations}

${decl.implementation}
  
#undef ${HEADER_IMPLEMENTATION}

#endif // ${HEADER_IMPLEMENTATION}
`;
};