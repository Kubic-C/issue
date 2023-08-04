cmake_minimum_required(VERSION "3.12")
project("bug")

add_subdirectory(flecs)

add_executable(the-bug "src/main.cpp")
target_link_libraries(the-bug PUBLIC flecs_static)