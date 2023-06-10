cmake_minimum_required(VERSION 3.18.0 FATAL_ERROR)

if(NOT DEFINED INSANE_VERSION)
    set(INSANE_VERSION_MAJOR 0)
    set(INSANE_VERSION_MINOR 1)
    set(INSANE_VERSION_PATCH 0)
    set(INSANE_VERSION ${INSANE_VERSION_MAJOR}.${INSANE_VERSION_MINOR}.${INSANE_VERSION_PATCH})
endif()

project(
    insane-engine
    DESCRIPTION "An insane engine developed and maintained for no reason"
    VERSION ${INSANE_VERSION}
)

set(INSANE_PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(INSANE_BUILD_DIR   "${CMAKE_CURRENT_BINARY_DIR}")

if(CMAKE_SOURCE_DIR STREQUAL INSANE_PROJECT_DIR)
    set(INSANE_STANDALONE_BUILD ON)
else()
    set(INSANE_STANDALONE_BUILD OFF)
endif()

message(STATUS "Insane engine")
message(STATUS " \\__Version: ${INSANE_VERSION}")
message(STATUS " \\__Project directory: ${INSANE_PROJECT_DIR}")
message(STATUS " \\__Build directory: ${INSANE_BUILD_DIR}")
message(STATUS " \\__Standalone build: ${INSANE_STANDALONE_BUILD}")