cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

#########################################
## Message Project Name and version in config step
## configure: cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -H. -G Ninja -B build/debug
## build:     cmake --build build/debug
#########################################

#########################################
## configure and message Project Name and version in config step
#########################################
project(code_snippets
    VERSION 0.1.0
    LANGUAGES C CXX ASM
    )
message(STATUS "configure ${PROJECT_NAME} version: ${PROJECT_VERSION}")

#########################################
## Configure Variables
#########################################
set(SETTINGS_FILE_NAME ${PROJECT_NAME})
string(APPEND SETTINGS_FILE_NAME ".ini")

#########################################
## pass Cmake Variables/Config to compilation
#########################################
configure_file(config.h.in config.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#########################################
## generate compile database and create symlink
#########################################
if( CMAKE_EXPORT_COMPILE_COMMANDS STREQUAL "ON")
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E create_symlink
          ${CMAKE_BINARY_DIR}/compile_commands.json
          ${CMAKE_SOURCE_DIR}/compile_commands.json
    )
endif()

#########################################
## verbose build
#########################################
SET(CMAKE_VERBOSE_MAKEFILE ON)

#########################################
## Global compiler settings
#########################################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#########################################
## Strict compile options
#########################################
add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wstrict-aliasing
    -Werror
)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" )
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS}" )
SET(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS}" )

#########################################
## add executable
#########################################
add_executable(user_interaction
        user_interaction/main.cpp
    )

