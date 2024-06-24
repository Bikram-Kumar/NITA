cmake_minimum_required(VERSION 3.10)

project(a.out)

add_executable(
    a.out
    main.c
)

add_subdirectory(./lib/DStruct)

target_link_libraries(a.out DStruct)

