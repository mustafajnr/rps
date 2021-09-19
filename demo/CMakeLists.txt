cmake_minimum_required(VERSION 3.18)
project(rps)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB rps_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(rpsl ${rps_SRC})
target_link_libraries(rpsl -static-libstdc++)