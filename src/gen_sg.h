#ifndef CALO_GEN_SG_H
#define CALO_GEN_SG_H

#include <stdint.h>
#include <stdbool.h>

#include "calo.h"
#include <ek/math.h>
#include <ek/hash.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*** types ***/

struct sg_scene_info_;
struct sg_file_;
struct sg_frame_script_;
struct sg_frame_label_;
struct sg_keyframe_transform_;
struct sg_easing_;
struct sg_movie_frame_;
struct sg_movie_layer_;
struct sg_movie_;
struct sg_text_layer_;
struct sg_dynamic_text_;
struct sg_node_data_;
struct sg_filter_;
struct model3d_vertex_;
struct model3d_;
struct sprite_info_;
struct atlas_page_info_;
struct atlas_info_;
typedef struct sg_scene_info_ {
	string_hash_t name;
	string_hash_t linkage;
} sg_scene_info_t;

typedef sg_scene_info_t* sg_scene_info_array_t;

typedef string_hash_t* string_hash_array_t;

typedef struct sg_file_ {
	string_hash_t* scenes;
	struct sg_scene_info_* linkages;
	struct sg_node_data_* library;
} sg_file_t;

typedef struct sg_frame_script_ {
	int32_t frame;
	const char* code;
} sg_frame_script_t;

typedef sg_frame_script_t* sg_frame_script_array_t;

typedef struct sg_frame_label_ {
	int32_t frame;
	const char* name;
} sg_frame_label_t;

typedef sg_frame_label_t* sg_frame_label_array_t;

typedef struct sg_keyframe_transform_ {
	vec2_t position;
	vec2_t scale;
	vec2_t skew;
	vec2_t pivot;
	color2f_t color;
} sg_keyframe_transform_t;

typedef vec2_t* vec2_array_t;

typedef struct sg_easing_ {
	float ease;
	vec2_t* curve;
	uint8_t attribute;
} sg_easing_t;

typedef sg_easing_t* sg_easing_array_t;

typedef struct sg_movie_frame_ {
	int32_t index;
	int32_t duration;
	int32_t motion_type;
	struct sg_easing_* easing;
	sg_keyframe_transform_t transform;
	bool visible;
	int32_t loop_mode;
	int32_t first_frame;
	int32_t rotate;
	int32_t rotate_times;
} sg_movie_frame_t;

typedef sg_movie_frame_t* sg_movie_frame_array_t;

typedef struct sg_movie_layer_ {
	struct sg_movie_frame_* frames;
	struct sg_node_data_ ** targets;
} sg_movie_layer_t;

typedef sg_movie_layer_t* sg_movie_layer_array_t;

typedef struct sg_movie_ {
	int32_t frames;
	float fps;
	struct sg_movie_layer_* layers;
} sg_movie_t;

typedef sg_movie_t* sg_movie_array_t;

typedef struct sg_text_layer_ {
	color_t color;
	vec2_t offset;
	float blur_radius;
	uint32_t blur_iterations;
	uint32_t strength;
} sg_text_layer_t;

typedef sg_text_layer_t* sg_text_layer_array_t;

typedef struct sg_dynamic_text_ {
	const char* text;
	string_hash_t font;
	float size;
	vec2_t alignment;
	rect_t rect;
	float line_spacing;
	float line_height;
	struct sg_text_layer_* layers;
	bool word_wrap;
} sg_dynamic_text_t;

typedef sg_dynamic_text_t* sg_dynamic_text_array_t;

typedef struct sg_node_data_* sg_node_data_struct_array_t;

typedef struct sg_node_data_ {
	mat3x2_t matrix;
	color2f_t color;
	string_hash_t name;
	string_hash_t library_name;
	string_hash_t sprite;
	bool button;
	bool touchable;
	bool visible;
	bool scissors_enabled;
	bool hit_area_enabled;
	bool bounds_enabled;
	rect_t bounding_rect;
	rect_t scale_grid;
	struct sg_node_data_* children;
	struct sg_dynamic_text_* dynamic_text;
	struct sg_movie_* movie;
	struct sg_frame_label_* labels;
	struct sg_frame_script_* scripts;
	int32_t movie_target_id;
} sg_node_data_t;

typedef enum {
   SG_FILTER_NONE = 0,
   SG_FILTER_SHADOW = 1,
   SG_FILTER_GLOW = 2
} sg_filter_type_t;

typedef struct sg_filter_ {
	sg_filter_type_t type;
	uint32_t quality;
	color_t color;
	vec2_t blur;
	vec2_t offset;
} sg_filter_t;

typedef uint16_t* u16_array_t;

typedef struct model3d_vertex_ {
	vec3_t position;
	vec3_t normal;
	vec2_t uv;
	color_t color;
	color_t color2;
} model3d_vertex_t;

typedef model3d_vertex_t* model3d_vertex_array_t;

typedef struct model3d_ {
	struct model3d_vertex_* vertices;
	uint16_t* indices;
} model3d_t;

typedef struct sprite_info_ {
	string_hash_t name;
	uint32_t flags;
	rect_t rc;
	rect_t uv;
} sprite_info_t;

typedef sprite_info_t* sprite_info_array_t;

typedef struct atlas_page_info_ {
	uint16_t width;
	uint16_t height;
	const char* image_path;
	struct sprite_info_* sprites;
} atlas_page_info_t;

typedef atlas_page_info_t* atlas_page_info_array_t;

typedef struct atlas_info_ {
	struct atlas_page_info_* pages;
} atlas_info_t;


/*** functions ***/

sg_scene_info_t read_stream_sg_scene_info(calo_reader_t* r);

void write_stream_sg_scene_info(calo_writer_t* w, sg_scene_info_t v);

sg_scene_info_array_t read_stream_sg_scene_info_array(calo_reader_t* r);

void write_stream_sg_scene_info_array(calo_writer_t* w, sg_scene_info_array_t v);

string_hash_array_t read_stream_string_hash_array(calo_reader_t* r);

void write_stream_string_hash_array(calo_writer_t* w, string_hash_array_t v);

sg_file_t read_stream_sg_file(calo_reader_t* r);

void write_stream_sg_file(calo_writer_t* w, sg_file_t v);

sg_frame_script_t read_stream_sg_frame_script(calo_reader_t* r);

void write_stream_sg_frame_script(calo_writer_t* w, sg_frame_script_t v);

sg_frame_script_array_t read_stream_sg_frame_script_array(calo_reader_t* r);

void write_stream_sg_frame_script_array(calo_writer_t* w, sg_frame_script_array_t v);

sg_frame_label_t read_stream_sg_frame_label(calo_reader_t* r);

void write_stream_sg_frame_label(calo_writer_t* w, sg_frame_label_t v);

sg_frame_label_array_t read_stream_sg_frame_label_array(calo_reader_t* r);

void write_stream_sg_frame_label_array(calo_writer_t* w, sg_frame_label_array_t v);

sg_keyframe_transform_t read_stream_sg_keyframe_transform(calo_reader_t* r);

void write_stream_sg_keyframe_transform(calo_writer_t* w, sg_keyframe_transform_t v);

vec2_array_t read_stream_vec2_array(calo_reader_t* r);

void write_stream_vec2_array(calo_writer_t* w, vec2_array_t v);

sg_easing_t read_stream_sg_easing(calo_reader_t* r);

void write_stream_sg_easing(calo_writer_t* w, sg_easing_t v);

sg_easing_array_t read_stream_sg_easing_array(calo_reader_t* r);

void write_stream_sg_easing_array(calo_writer_t* w, sg_easing_array_t v);

sg_movie_frame_t read_stream_sg_movie_frame(calo_reader_t* r);

void write_stream_sg_movie_frame(calo_writer_t* w, sg_movie_frame_t v);

sg_movie_frame_array_t read_stream_sg_movie_frame_array(calo_reader_t* r);

void write_stream_sg_movie_frame_array(calo_writer_t* w, sg_movie_frame_array_t v);

sg_movie_layer_t read_stream_sg_movie_layer(calo_reader_t* r);

void write_stream_sg_movie_layer(calo_writer_t* w, sg_movie_layer_t v);

sg_movie_layer_array_t read_stream_sg_movie_layer_array(calo_reader_t* r);

void write_stream_sg_movie_layer_array(calo_writer_t* w, sg_movie_layer_array_t v);

sg_movie_t read_stream_sg_movie(calo_reader_t* r);

void write_stream_sg_movie(calo_writer_t* w, sg_movie_t v);

sg_movie_array_t read_stream_sg_movie_array(calo_reader_t* r);

void write_stream_sg_movie_array(calo_writer_t* w, sg_movie_array_t v);

sg_text_layer_t read_stream_sg_text_layer(calo_reader_t* r);

void write_stream_sg_text_layer(calo_writer_t* w, sg_text_layer_t v);

sg_text_layer_array_t read_stream_sg_text_layer_array(calo_reader_t* r);

void write_stream_sg_text_layer_array(calo_writer_t* w, sg_text_layer_array_t v);

sg_dynamic_text_t read_stream_sg_dynamic_text(calo_reader_t* r);

void write_stream_sg_dynamic_text(calo_writer_t* w, sg_dynamic_text_t v);

sg_dynamic_text_array_t read_stream_sg_dynamic_text_array(calo_reader_t* r);

void write_stream_sg_dynamic_text_array(calo_writer_t* w, sg_dynamic_text_array_t v);

sg_node_data_struct_array_t read_stream_sg_node_data_struct_array(calo_reader_t* r);

void write_stream_sg_node_data_struct_array(calo_writer_t* w, sg_node_data_struct_array_t v);

vec4_t read_stream_vec4(calo_reader_t* r);

void write_stream_vec4(calo_writer_t* w, vec4_t v);

color2f_t read_stream_color2f(calo_reader_t* r);

void write_stream_color2f(calo_writer_t* w, color2f_t v);

mat2_t read_stream_mat2(calo_reader_t* r);

void write_stream_mat2(calo_writer_t* w, mat2_t v);

mat3x2_t read_stream_mat3x2(calo_reader_t* r);

void write_stream_mat3x2(calo_writer_t* w, mat3x2_t v);

sg_node_data_t read_stream_sg_node_data(calo_reader_t* r);

void write_stream_sg_node_data(calo_writer_t* w, sg_node_data_t v);

sg_filter_t read_stream_sg_filter(calo_reader_t* r);

void write_stream_sg_filter(calo_writer_t* w, sg_filter_t v);

u16_array_t read_stream_u16_array(calo_reader_t* r);

void write_stream_u16_array(calo_writer_t* w, u16_array_t v);

color_t read_stream_color(calo_reader_t* r);

void write_stream_color(calo_writer_t* w, color_t v);

vec2_t read_stream_vec2(calo_reader_t* r);

void write_stream_vec2(calo_writer_t* w, vec2_t v);

vec3_t read_stream_vec3(calo_reader_t* r);

void write_stream_vec3(calo_writer_t* w, vec3_t v);

model3d_vertex_t read_stream_model3d_vertex(calo_reader_t* r);

void write_stream_model3d_vertex(calo_writer_t* w, model3d_vertex_t v);

model3d_vertex_array_t read_stream_model3d_vertex_array(calo_reader_t* r);

void write_stream_model3d_vertex_array(calo_writer_t* w, model3d_vertex_array_t v);

model3d_t read_stream_model3d(calo_reader_t* r);

void write_stream_model3d(calo_writer_t* w, model3d_t v);

rect_t read_stream_rect(calo_reader_t* r);

void write_stream_rect(calo_writer_t* w, rect_t v);

sprite_info_t read_stream_sprite_info(calo_reader_t* r);

void write_stream_sprite_info(calo_writer_t* w, sprite_info_t v);

sprite_info_array_t read_stream_sprite_info_array(calo_reader_t* r);

void write_stream_sprite_info_array(calo_writer_t* w, sprite_info_array_t v);

atlas_page_info_t read_stream_atlas_page_info(calo_reader_t* r);

void write_stream_atlas_page_info(calo_writer_t* w, atlas_page_info_t v);

atlas_page_info_array_t read_stream_atlas_page_info_array(calo_reader_t* r);

void write_stream_atlas_page_info_array(calo_writer_t* w, atlas_page_info_array_t v);

atlas_info_t read_stream_atlas_info(calo_reader_t* r);

void write_stream_atlas_info(calo_writer_t* w, atlas_info_t v);

// functions

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CALO_GEN_SG_H

/*** implementation ***/

#ifdef CALO_GEN_SG_IMPLEMENTATION
#ifdef CALO_GEN_SG_IMPLEMENTED
#error implementation should be included only once
#else
#define CALO_GEN_SG_IMPLEMENTED
#endif // CALO_GEN_SG_IMPLEMENTED

#include <ek/buf.h>



sg_scene_info_t read_stream_sg_scene_info(calo_reader_t* r) {
    sg_scene_info_t val;
	val.name = read_u32(r);
	val.linkage = read_u32(r);
    return val;
}

void write_stream_sg_scene_info(calo_writer_t* w, sg_scene_info_t v) {
	write_u32(w, v.name);
	write_u32(w, v.linkage);
}

sg_scene_info_array_t read_stream_sg_scene_info_array(calo_reader_t* r) {
    sg_scene_info_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_scene_info(r);
        }
    }
    return val;
}

void write_stream_sg_scene_info_array(calo_writer_t* w, sg_scene_info_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_scene_info(w, v[i]);
        }
    }
}

string_hash_array_t read_stream_string_hash_array(calo_reader_t* r) {
    string_hash_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_u32(r);
        }
    }
    return val;
}

void write_stream_string_hash_array(calo_writer_t* w, string_hash_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_u32(w, v[i]);
        }
    }
}

sg_file_t read_stream_sg_file(calo_reader_t* r) {
    sg_file_t val;
	val.scenes = read_stream_string_hash_array(r);
	val.linkages = read_stream_sg_scene_info_array(r);
	val.library = read_stream_sg_node_data_struct_array(r);
    return val;
}

void write_stream_sg_file(calo_writer_t* w, sg_file_t v) {
	write_stream_string_hash_array(w, v.scenes);
	write_stream_sg_scene_info_array(w, v.linkages);
	write_stream_sg_node_data_struct_array(w, v.library);
}

sg_frame_script_t read_stream_sg_frame_script(calo_reader_t* r) {
    sg_frame_script_t val;
	val.frame = read_i32(r);
	val.code = read_stream_string(r);
    return val;
}

void write_stream_sg_frame_script(calo_writer_t* w, sg_frame_script_t v) {
	write_i32(w, v.frame);
	write_stream_string(w, v.code);
}

sg_frame_script_array_t read_stream_sg_frame_script_array(calo_reader_t* r) {
    sg_frame_script_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_frame_script(r);
        }
    }
    return val;
}

void write_stream_sg_frame_script_array(calo_writer_t* w, sg_frame_script_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_frame_script(w, v[i]);
        }
    }
}

sg_frame_label_t read_stream_sg_frame_label(calo_reader_t* r) {
    sg_frame_label_t val;
	val.frame = read_i32(r);
	val.name = read_stream_string(r);
    return val;
}

void write_stream_sg_frame_label(calo_writer_t* w, sg_frame_label_t v) {
	write_i32(w, v.frame);
	write_stream_string(w, v.name);
}

sg_frame_label_array_t read_stream_sg_frame_label_array(calo_reader_t* r) {
    sg_frame_label_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_frame_label(r);
        }
    }
    return val;
}

void write_stream_sg_frame_label_array(calo_writer_t* w, sg_frame_label_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_frame_label(w, v[i]);
        }
    }
}

sg_keyframe_transform_t read_stream_sg_keyframe_transform(calo_reader_t* r) {
    sg_keyframe_transform_t val;
	val.position = read_stream_vec2(r);
	val.scale = read_stream_vec2(r);
	val.skew = read_stream_vec2(r);
	val.pivot = read_stream_vec2(r);
	val.color = read_stream_color2f(r);
    return val;
}

void write_stream_sg_keyframe_transform(calo_writer_t* w, sg_keyframe_transform_t v) {
	write_stream_vec2(w, v.position);
	write_stream_vec2(w, v.scale);
	write_stream_vec2(w, v.skew);
	write_stream_vec2(w, v.pivot);
	write_stream_color2f(w, v.color);
}

vec2_array_t read_stream_vec2_array(calo_reader_t* r) {
    vec2_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_vec2(r);
        }
    }
    return val;
}

void write_stream_vec2_array(calo_writer_t* w, vec2_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_vec2(w, v[i]);
        }
    }
}

sg_easing_t read_stream_sg_easing(calo_reader_t* r) {
    sg_easing_t val;
	val.ease = read_f32(r);
	val.curve = read_stream_vec2_array(r);
	val.attribute = read_u8(r);
    return val;
}

void write_stream_sg_easing(calo_writer_t* w, sg_easing_t v) {
	write_f32(w, v.ease);
	write_stream_vec2_array(w, v.curve);
	write_u8(w, v.attribute);
}

sg_easing_array_t read_stream_sg_easing_array(calo_reader_t* r) {
    sg_easing_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_easing(r);
        }
    }
    return val;
}

void write_stream_sg_easing_array(calo_writer_t* w, sg_easing_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_easing(w, v[i]);
        }
    }
}

sg_movie_frame_t read_stream_sg_movie_frame(calo_reader_t* r) {
    sg_movie_frame_t val;
	val.index = read_i32(r);
	val.duration = read_i32(r);
	val.motion_type = read_i32(r);
	val.easing = read_stream_sg_easing_array(r);
	val.transform = read_stream_sg_keyframe_transform(r);
	val.visible = read_u8(r);
	val.loop_mode = read_i32(r);
	val.first_frame = read_i32(r);
	val.rotate = read_i32(r);
	val.rotate_times = read_i32(r);
    return val;
}

void write_stream_sg_movie_frame(calo_writer_t* w, sg_movie_frame_t v) {
	write_i32(w, v.index);
	write_i32(w, v.duration);
	write_i32(w, v.motion_type);
	write_stream_sg_easing_array(w, v.easing);
	write_stream_sg_keyframe_transform(w, v.transform);
	write_u8(w, v.visible);
	write_i32(w, v.loop_mode);
	write_i32(w, v.first_frame);
	write_i32(w, v.rotate);
	write_i32(w, v.rotate_times);
}

sg_movie_frame_array_t read_stream_sg_movie_frame_array(calo_reader_t* r) {
    sg_movie_frame_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_movie_frame(r);
        }
    }
    return val;
}

void write_stream_sg_movie_frame_array(calo_writer_t* w, sg_movie_frame_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_movie_frame(w, v[i]);
        }
    }
}

sg_movie_layer_t read_stream_sg_movie_layer(calo_reader_t* r) {
    sg_movie_layer_t val;
	val.frames = read_stream_sg_movie_frame_array(r);
    return val;
}

void write_stream_sg_movie_layer(calo_writer_t* w, sg_movie_layer_t v) {
	write_stream_sg_movie_frame_array(w, v.frames);
}

sg_movie_layer_array_t read_stream_sg_movie_layer_array(calo_reader_t* r) {
    sg_movie_layer_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_movie_layer(r);
        }
    }
    return val;
}

void write_stream_sg_movie_layer_array(calo_writer_t* w, sg_movie_layer_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_movie_layer(w, v[i]);
        }
    }
}

sg_movie_t read_stream_sg_movie(calo_reader_t* r) {
    sg_movie_t val;
	val.frames = read_i32(r);
	val.fps = read_f32(r);
	val.layers = read_stream_sg_movie_layer_array(r);
    return val;
}

void write_stream_sg_movie(calo_writer_t* w, sg_movie_t v) {
	write_i32(w, v.frames);
	write_f32(w, v.fps);
	write_stream_sg_movie_layer_array(w, v.layers);
}

sg_movie_array_t read_stream_sg_movie_array(calo_reader_t* r) {
    sg_movie_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_movie(r);
        }
    }
    return val;
}

void write_stream_sg_movie_array(calo_writer_t* w, sg_movie_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_movie(w, v[i]);
        }
    }
}

sg_text_layer_t read_stream_sg_text_layer(calo_reader_t* r) {
    sg_text_layer_t val;
	val.color = read_stream_color(r);
	val.offset = read_stream_vec2(r);
	val.blur_radius = read_f32(r);
	val.blur_iterations = read_u32(r);
	val.strength = read_u32(r);
    return val;
}

void write_stream_sg_text_layer(calo_writer_t* w, sg_text_layer_t v) {
	write_stream_color(w, v.color);
	write_stream_vec2(w, v.offset);
	write_f32(w, v.blur_radius);
	write_u32(w, v.blur_iterations);
	write_u32(w, v.strength);
}

sg_text_layer_array_t read_stream_sg_text_layer_array(calo_reader_t* r) {
    sg_text_layer_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_text_layer(r);
        }
    }
    return val;
}

void write_stream_sg_text_layer_array(calo_writer_t* w, sg_text_layer_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_text_layer(w, v[i]);
        }
    }
}

sg_dynamic_text_t read_stream_sg_dynamic_text(calo_reader_t* r) {
    sg_dynamic_text_t val;
	val.text = read_stream_string(r);
	val.font = read_u32(r);
	val.size = read_f32(r);
	val.alignment = read_stream_vec2(r);
	val.rect = read_stream_rect(r);
	val.line_spacing = read_f32(r);
	val.line_height = read_f32(r);
	val.layers = read_stream_sg_text_layer_array(r);
	val.word_wrap = read_u8(r);
    return val;
}

void write_stream_sg_dynamic_text(calo_writer_t* w, sg_dynamic_text_t v) {
	write_stream_string(w, v.text);
	write_u32(w, v.font);
	write_f32(w, v.size);
	write_stream_vec2(w, v.alignment);
	write_stream_rect(w, v.rect);
	write_f32(w, v.line_spacing);
	write_f32(w, v.line_height);
	write_stream_sg_text_layer_array(w, v.layers);
	write_u8(w, v.word_wrap);
}

sg_dynamic_text_array_t read_stream_sg_dynamic_text_array(calo_reader_t* r) {
    sg_dynamic_text_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_dynamic_text(r);
        }
    }
    return val;
}

void write_stream_sg_dynamic_text_array(calo_writer_t* w, sg_dynamic_text_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_dynamic_text(w, v[i]);
        }
    }
}

sg_node_data_struct_array_t read_stream_sg_node_data_struct_array(calo_reader_t* r) {
    sg_node_data_struct_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sg_node_data(r);
        }
    }
    return val;
}

void write_stream_sg_node_data_struct_array(calo_writer_t* w, sg_node_data_struct_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sg_node_data(w, v[i]);
        }
    }
}

vec4_t read_stream_vec4(calo_reader_t* r) {
    vec4_t val;
	val.x = read_f32(r);
	val.y = read_f32(r);
	val.z = read_f32(r);
	val.w = read_f32(r);
    return val;
}

void write_stream_vec4(calo_writer_t* w, vec4_t v) {
	write_f32(w, v.x);
	write_f32(w, v.y);
	write_f32(w, v.z);
	write_f32(w, v.w);
}

color2f_t read_stream_color2f(calo_reader_t* r) {
    color2f_t val;
	val.scale = read_stream_vec4(r);
	val.offset = read_stream_vec4(r);
    return val;
}

void write_stream_color2f(calo_writer_t* w, color2f_t v) {
	write_stream_vec4(w, v.scale);
	write_stream_vec4(w, v.offset);
}

mat2_t read_stream_mat2(calo_reader_t* r) {
    mat2_t val;
	val.a = read_f32(r);
	val.b = read_f32(r);
	val.c = read_f32(r);
	val.d = read_f32(r);
    return val;
}

void write_stream_mat2(calo_writer_t* w, mat2_t v) {
	write_f32(w, v.a);
	write_f32(w, v.b);
	write_f32(w, v.c);
	write_f32(w, v.d);
}

mat3x2_t read_stream_mat3x2(calo_reader_t* r) {
    mat3x2_t val;
	val.rot = read_stream_mat2(r);
	val.pos = read_stream_vec2(r);
    return val;
}

void write_stream_mat3x2(calo_writer_t* w, mat3x2_t v) {
	write_stream_mat2(w, v.rot);
	write_stream_vec2(w, v.pos);
}

sg_node_data_t read_stream_sg_node_data(calo_reader_t* r) {
    sg_node_data_t val;
	val.matrix = read_stream_mat3x2(r);
	val.color = read_stream_color2f(r);
	val.name = read_u32(r);
	val.library_name = read_u32(r);
	val.sprite = read_u32(r);
	val.button = read_u8(r);
	val.touchable = read_u8(r);
	val.visible = read_u8(r);
	val.scissors_enabled = read_u8(r);
	val.hit_area_enabled = read_u8(r);
	val.bounds_enabled = read_u8(r);
	val.bounding_rect = read_stream_rect(r);
	val.scale_grid = read_stream_rect(r);
	val.children = read_stream_sg_node_data_struct_array(r);
	val.dynamic_text = read_stream_sg_dynamic_text_array(r);
	val.movie = read_stream_sg_movie_array(r);
	val.labels = read_stream_sg_frame_label_array(r);
	val.scripts = read_stream_sg_frame_script_array(r);
	val.movie_target_id = read_i32(r);
    return val;
}

void write_stream_sg_node_data(calo_writer_t* w, sg_node_data_t v) {
	write_stream_mat3x2(w, v.matrix);
	write_stream_color2f(w, v.color);
	write_u32(w, v.name);
	write_u32(w, v.library_name);
	write_u32(w, v.sprite);
	write_u8(w, v.button);
	write_u8(w, v.touchable);
	write_u8(w, v.visible);
	write_u8(w, v.scissors_enabled);
	write_u8(w, v.hit_area_enabled);
	write_u8(w, v.bounds_enabled);
	write_stream_rect(w, v.bounding_rect);
	write_stream_rect(w, v.scale_grid);
	write_stream_sg_node_data_struct_array(w, v.children);
	write_stream_sg_dynamic_text_array(w, v.dynamic_text);
	write_stream_sg_movie_array(w, v.movie);
	write_stream_sg_frame_label_array(w, v.labels);
	write_stream_sg_frame_script_array(w, v.scripts);
	write_i32(w, v.movie_target_id);
}

sg_filter_t read_stream_sg_filter(calo_reader_t* r) {
    sg_filter_t val;
	val.type = read_u32(r);
	val.quality = read_u32(r);
	val.color = read_stream_color(r);
	val.blur = read_stream_vec2(r);
	val.offset = read_stream_vec2(r);
    return val;
}

void write_stream_sg_filter(calo_writer_t* w, sg_filter_t v) {
	write_u32(w, v.type);
	write_u32(w, v.quality);
	write_stream_color(w, v.color);
	write_stream_vec2(w, v.blur);
	write_stream_vec2(w, v.offset);
}

u16_array_t read_stream_u16_array(calo_reader_t* r) {
    u16_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_u16(r);
        }
    }
    return val;
}

void write_stream_u16_array(calo_writer_t* w, u16_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_u16(w, v[i]);
        }
    }
}

color_t read_stream_color(calo_reader_t* r) {
    color_t val;
	val.value = read_u32(r);
    return val;
}

void write_stream_color(calo_writer_t* w, color_t v) {
	write_u32(w, v.value);
}

vec2_t read_stream_vec2(calo_reader_t* r) {
    vec2_t val;
	val.x = read_f32(r);
	val.y = read_f32(r);
    return val;
}

void write_stream_vec2(calo_writer_t* w, vec2_t v) {
	write_f32(w, v.x);
	write_f32(w, v.y);
}

vec3_t read_stream_vec3(calo_reader_t* r) {
    vec3_t val;
	val.x = read_f32(r);
	val.y = read_f32(r);
	val.z = read_f32(r);
    return val;
}

void write_stream_vec3(calo_writer_t* w, vec3_t v) {
	write_f32(w, v.x);
	write_f32(w, v.y);
	write_f32(w, v.z);
}

model3d_vertex_t read_stream_model3d_vertex(calo_reader_t* r) {
    model3d_vertex_t val;
	val.position = read_stream_vec3(r);
	val.normal = read_stream_vec3(r);
	val.uv = read_stream_vec2(r);
	val.color = read_stream_color(r);
	val.color2 = read_stream_color(r);
    return val;
}

void write_stream_model3d_vertex(calo_writer_t* w, model3d_vertex_t v) {
	write_stream_vec3(w, v.position);
	write_stream_vec3(w, v.normal);
	write_stream_vec2(w, v.uv);
	write_stream_color(w, v.color);
	write_stream_color(w, v.color2);
}

model3d_vertex_array_t read_stream_model3d_vertex_array(calo_reader_t* r) {
    model3d_vertex_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_model3d_vertex(r);
        }
    }
    return val;
}

void write_stream_model3d_vertex_array(calo_writer_t* w, model3d_vertex_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_model3d_vertex(w, v[i]);
        }
    }
}

model3d_t read_stream_model3d(calo_reader_t* r) {
    model3d_t val;
	val.vertices = read_stream_model3d_vertex_array(r);
	val.indices = read_stream_u16_array(r);
    return val;
}

void write_stream_model3d(calo_writer_t* w, model3d_t v) {
	write_stream_model3d_vertex_array(w, v.vertices);
	write_stream_u16_array(w, v.indices);
}

rect_t read_stream_rect(calo_reader_t* r) {
    rect_t val;
	val.x = read_f32(r);
	val.y = read_f32(r);
	val.w = read_f32(r);
	val.h = read_f32(r);
    return val;
}

void write_stream_rect(calo_writer_t* w, rect_t v) {
	write_f32(w, v.x);
	write_f32(w, v.y);
	write_f32(w, v.w);
	write_f32(w, v.h);
}

sprite_info_t read_stream_sprite_info(calo_reader_t* r) {
    sprite_info_t val;
	val.name = read_u32(r);
	val.flags = read_u32(r);
	val.rc = read_stream_rect(r);
	val.uv = read_stream_rect(r);
    return val;
}

void write_stream_sprite_info(calo_writer_t* w, sprite_info_t v) {
	write_u32(w, v.name);
	write_u32(w, v.flags);
	write_stream_rect(w, v.rc);
	write_stream_rect(w, v.uv);
}

sprite_info_array_t read_stream_sprite_info_array(calo_reader_t* r) {
    sprite_info_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_sprite_info(r);
        }
    }
    return val;
}

void write_stream_sprite_info_array(calo_writer_t* w, sprite_info_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_sprite_info(w, v[i]);
        }
    }
}

atlas_page_info_t read_stream_atlas_page_info(calo_reader_t* r) {
    atlas_page_info_t val;
	val.width = read_u16(r);
	val.height = read_u16(r);
	val.image_path = read_stream_string(r);
	val.sprites = read_stream_sprite_info_array(r);
    return val;
}

void write_stream_atlas_page_info(calo_writer_t* w, atlas_page_info_t v) {
	write_u16(w, v.width);
	write_u16(w, v.height);
	write_stream_string(w, v.image_path);
	write_stream_sprite_info_array(w, v.sprites);
}

atlas_page_info_array_t read_stream_atlas_page_info_array(calo_reader_t* r) {
    atlas_page_info_array_t val;
    {
        uint32_t count = read_u32(r);
        val = 0;
        ek_buf_set_size((void**)&val, sizeof val[0], count, count);
        for(uint32_t i = 0; i < count; ++i) {
            val[i] = read_stream_atlas_page_info(r);
        }
    }
    return val;
}

void write_stream_atlas_page_info_array(calo_writer_t* w, atlas_page_info_array_t v) {
    {
        uint32_t count = ek_buf_length(v);
        write_u32(w, count);
        for(uint32_t i = 0; i < count; ++i) {
            write_stream_atlas_page_info(w, v[i]);
        }
    }
}

atlas_info_t read_stream_atlas_info(calo_reader_t* r) {
    atlas_info_t val;
	val.pages = read_stream_atlas_page_info_array(r);
    return val;
}

void write_stream_atlas_info(calo_writer_t* w, atlas_info_t v) {
	write_stream_atlas_page_info_array(w, v.pages);
}
  
#undef CALO_GEN_SG_IMPLEMENTATION

#endif // CALO_GEN_SG_IMPLEMENTATION
