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