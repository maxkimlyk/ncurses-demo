cmake_minimum_required(VERSION 3.12)

project(ncurses-demo)

file(GLOB SRC "*.cpp")

foreach(src_ ${SRC})
    get_filename_component(name_we_ ${src_} NAME_WE)
    add_executable(${name_we_} ${src_})
    target_link_libraries(${name_we_} ncursesw)
endforeach()
