# This is a copy of <PICOPAD_BASE_PATH>/external/picopad_base_import.cmake

# This can be dropped into an external project to help locate picopad_base
# It should be include()ed prior to project()

if (DEFINED ENV{PICOPAD_BASE_PATH} AND (NOT PICOPAD_BASE_PATH))
    set(PICOPAD_BASE_PATH $ENV{PICOPAD_BASE_PATH})
    message("Using PICOPAD_BASE_PATH from environment ('${PICOPAD_BASE_PATH}')")
endif ()

if (DEFINED ENV{PICOPAD_BASE_FETCH_FROM_GIT} AND (NOT PICOPAD_BASE_FETCH_FROM_GIT))
    set(PICOPAD_BASE_FETCH_FROM_GIT $ENV{PICOPAD_BASE_FETCH_FROM_GIT})
    message("Using PICOPAD_BASE_FETCH_FROM_GIT from environment ('${PICOPAD_BASE_FETCH_FROM_GIT}')")
endif ()

if (DEFINED ENV{PICOPAD_BASE_FETCH_FROM_GIT_PATH} AND (NOT PICOPAD_BASE_FETCH_FROM_GIT_PATH))
    set(PICOPAD_BASE_FETCH_FROM_GIT_PATH $ENV{PICOPAD_BASE_FETCH_FROM_GIT_PATH})
    message("Using PICOPAD_BASE_FETCH_FROM_GIT_PATH from environment ('${PICOPAD_BASE_FETCH_FROM_GIT_PATH}')")
endif ()

if (NOT PICOPAD_BASE_PATH)
    if (PICOPAD_BASE_FETCH_FROM_GIT)
        include(FetchContent)
        set(FETCHCONTENT_BASE_DIR_SAVE ${FETCHCONTENT_BASE_DIR})
        if (PICOPAD_BASE_FETCH_FROM_GIT_PATH)
            get_filename_component(FETCHCONTENT_BASE_DIR "${PICOPAD_BASE_FETCH_FROM_GIT_PATH}" REALPATH BASE_DIR "${CMAKE_SOURCE_DIR}")
        endif ()
        FetchContent_Declare(
                picopad_base
                GIT_REPOSITORY https://github.com/bizzehdee/picopad_base
                GIT_TAG master
        )
        if (NOT picopad_base)
            message("Downloading Raspberry Pi Pico Extras")
            FetchContent_Populate(picopad_base)
            set(PICOPAD_BASE_PATH ${picopad_base_SOURCE_DIR})
        endif ()
        set(FETCHCONTENT_BASE_DIR ${FETCHCONTENT_BASE_DIR_SAVE})
    else ()
        if (PICO_SDK_PATH AND EXISTS "${PICO_SDK_PATH}/../picopad_base")
            set(PICOPAD_BASE_PATH ${PICO_SDK_PATH}/../picopad_base)
            message("Defaulting PICOPAD_BASE_PATH as sibling of PICO_SDK_PATH: ${PICOPAD_BASE_PATH}")
        else()
            message(FATAL_ERROR
                    "PICOPAD BASE location was not specified. Please set PICOPAD_BASE_PATH or set PICOPAD_BASE_FETCH_FROM_GIT to on to fetch from git."
                    )
        endif()
    endif ()
endif ()

set(PICOPAD_BASE_PATH "${PICOPAD_BASE_PATH}" CACHE PATH "Path to the PICOPAD BASE")
set(PICOPAD_BASE_FETCH_FROM_GIT "${PICOPAD_BASE_FETCH_FROM_GIT}" CACHE BOOL "Set to ON to fetch copy of PICOPAD BASE from git if not otherwise locatable")
set(PICOPAD_BASE_FETCH_FROM_GIT_PATH "${PICOPAD_BASE_FETCH_FROM_GIT_PATH}" CACHE FILEPATH "location to download BASE")

get_filename_component(PICOPAD_BASE_PATH "${PICOPAD_BASE_PATH}" REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
if (NOT EXISTS ${PICOPAD_BASE_PATH})
    message(FATAL_ERROR "Directory '${PICOPAD_BASE_PATH}' not found")
endif ()

set(PICOPAD_BASE_PATH ${PICOPAD_BASE_PATH} CACHE PATH "Path to the PICO BASE" FORCE)

add_subdirectory(${PICOPAD_BASE_PATH} picopad_base)
