cmake_minimum_required(VERSION 2.8)

project(craft)

FILE(GLOB SOURCE_FILES src/*.c)

#
#find_package(OpenAL REQUIRED)
#include_directories(${ALUT_INCLUDE_DIR})
#include_directories(${OPENAL_INCLUDE_DIR})
#target_link_libraries(craft ${ALUT_LIBRARY})
#target_link_libraries(craft ${OPENAL_LIBRARY})
#add_definitions("-DHAVE_OPENAL=1")

#arget_link_libraries(/usr/include/AL/alut.h)
#link_directories(${OPEN})
#include_directories(${OPENAL_INCLUDE_DIR})
#target_link_libraries(${OPENAL_LIBRARY})
#target_link_libraries(craft /usr/local/include/AL/alut.h)
#et(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
#set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} --libs=freealut")
#set(GCC_COVERAGE_COMPILE_FLAGS "-lopenal -lm")
#set(GCC_COVERAGE_LINK_FLAGS "-lopenal -lm")
#add_compile_options(--libs=freealut)
#add_definitions(-lopenal -lm)

#add_subdirectory(/usr/include/AL/)


add_executable(
    craft
    ${SOURCE_FILES}
    deps/glew/src/glew.c
    deps/lodepng/lodepng.c
    deps/noise/noise.c
    deps/sqlite/sqlite3.c
    deps/tinycthread/tinycthread.c)

add_definitions(-std=c99 -O3)

add_subdirectory(deps/glfw)
include_directories(deps/glew/include)
include_directories(deps/glfw/include)
include_directories(deps/lodepng)
include_directories(deps/noise)
include_directories(deps/sqlite)
include_directories(deps/tinycthread)

if(MINGW)
    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH}
        "C:/Program Files/CURL/lib" "C:/Program Files (x86)/CURL/lib")
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH}
        "C:/Program Files/CURL/include" "C:/Program Files (x86)/CURL/include")
endif()

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

if(APPLE)
    target_link_libraries(craft glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

if(UNIX)
    target_link_libraries(craft dl glfw 
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

if(MINGW)
    target_link_libraries(craft ws2_32.lib glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

find_package(OpenAL REQUIRED)
include_directories(${ALUT_INCLUDE_DIR})
include_directories(${OPENAL_INCLUDE_DIR})
target_link_libraries(craft ${ALUT_LIBRARY})
target_link_libraries(craft ${OPENAL_LIBRARY})
add_definitions("-DHAVE_OPENAL=1")
