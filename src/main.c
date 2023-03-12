#define CALO_IMPLEMENTATION

#include <stdio.h>
#include "calo.h"

#define CALO_GEN_SG_IMPLEMENTATION
#include "gen_sg.h"

int main() {

    sg_file_t file = {0};
    sg_node_data_t node = {0};
    sg_node_data_t node_ch = {0};
    sg_node_data_t node_ch2 = {0};
    sg_node_data_t node_ch3 = {0};
    arr_push(&node.children, sg_node_data_t, node_ch);
    arr_push(&node_ch.children, sg_node_data_t, node_ch2);
    arr_push(&node_ch2.children, sg_node_data_t, node_ch3);
    arr_push(&node.children, sg_node_data_t, node_ch);
    arr_push(&node.children, sg_node_data_t, node_ch);
    arr_push(&file.library, sg_node_data_t, node);
    arr_push(&file.library, sg_node_data_t, node);
    arr_push(&file.library, sg_node_data_t, node);
    arr_push(&file.library, sg_node_data_t, node);
    sg_scene_info_t linkage = {0};
    arr_push(&file.linkages, sg_scene_info_t , linkage);
    arr_push(&file.linkages, sg_scene_info_t , linkage);
    arr_push(&file.linkages, sg_scene_info_t , linkage);
    arr_push(&file.linkages, sg_scene_info_t , linkage);
    uint32_t s = 0x22;
    arr_push(&file.scenes, string_hash_t , s++);
    arr_push(&file.scenes, string_hash_t , s++);
    arr_push(&file.scenes, string_hash_t , s++);
    arr_push(&file.scenes, string_hash_t , s++);

    calo_writer_t writer = new_writer(1);
    write_stream_sg_file(&writer, file);

    FILE* f = fopen("test.sg", "wb");
    fwrite(writer.data, 1, writer.p - (uint8_t*)writer.data, f);
    fclose(f);

    uint32_t size;
    uint8_t* buf = read_file("test.sg", &size);
    calo_reader_t reader = {0};
    reader.p = buf;
    sg_file_t file2 = read_stream_sg_file(&reader);
    printf("%u %u %u %u \n",
           size,
           ek_buf_length(file2.library),
           ek_buf_length(file2.linkages),
           ek_buf_length(file2.scenes)
           );

    return 0;
}


int test_tables() {
    uint32_t indices[1024];
    uint32_t indices_num = 0;
    {
        vla_table_t tab = {0};
        indices[indices_num++] = add_string(&tab, "");
        indices[indices_num++] = add_string(&tab, "hello");
        indices[indices_num++] = add_string(&tab, "string2");
        indices[indices_num++] = add_string(&tab, "duplicated strings");
        indices[indices_num++] = add_string(&tab, "");
        indices[indices_num++] = add_string(&tab, "0\x00");
        indices[indices_num++] = add_string(&tab, "VERY VERY VERY VERY LONG STRING!");
        indices[indices_num++] = add_string(&tab, "duplicated strings");
        indices[indices_num++] = add_string(&tab, "duplicated strings");
        indices[indices_num++] = add_string(&tab, "duplicated strings");
        indices[indices_num++] = add_string(&tab, "duplicated strings");
        indices[indices_num++] = add_string(&tab, "duplicated strings");
        indices[indices_num++] = add_string(&tab, "duplicated strings");
        indices[indices_num++] = add_string(&tab, "duplicated strings");
        indices[indices_num++] = add_string(&tab, "{end of strings section}");

        FILE* f = fopen("test.alo", "wb");
        fwrite_table(&tab, f);
        fflush(f);
        fclose(f);
        free_table(&tab);
    }
    {
        void* mem = read_file("test.alo", 0);

        vla_table_t t = {0};
        map_table(&t, mem);

        printf("data section:\n");
        for (uint32_t i = 0; i < t.count; ++i) {
            printf("%u: %s\n", i, get_data(&t, i));
        }

        printf("\n restore order and strings:\n");
        for (uint32_t i = 0; i < indices_num; ++i) {
            printf("\"%s\"\n", get_data(&t, indices[i]));
        }

        // don't delete table, because it's mapped
        // free_table(&t);

        // free file content instead
        free(mem);
    }
    return 0;
}

