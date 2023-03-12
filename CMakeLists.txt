cmake_minimum_required(VERSION 3.19)
project(calo LANGUAGES C)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE src)
#target_include_directories(${PROJECT_NAME} INTERFACE ../ekx/packages/std/include)

add_executable(${PROJECT_NAME}_test src/main.c)
target_link_libraries(${PROJECT_NAME}_test
        INTERFACE ${PROJECT_NAME}
        PUBLIC ekx::std
        )
