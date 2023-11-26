cmake_minimum_required(VERSION 3.20.0)

set(BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "")
set(BOARD nucleo_h503rb CACHE PATH "")
find_package(Zephyr REQUIRED HINTS ${CMAKE_CURRENT_SOURCE_DIR}/..)

project(hello)

target_sources(app PRIVATE
    src/main.c
)
# target_link_libraries(hello PRIVATE )
