cmake_minimum_required(VERSION 3.13)

if (NOT TARGET _picopad_base_inclusion_marker)
    add_library(_picopad_base_inclusion_marker INTERFACE)

    # Pull in PICO SDK (must be before project)
    include(pico_sdk_import.cmake)
    if (PICO_SDK_VERSION_STRING VERSION_LESS "1.2.0")
        message(FATAL_ERROR "Require at least Raspberry Pi Pico SDK version 1.2.0")
    endif()

    project(picopad_base C CXX)

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 17)

    pico_is_top_level_project(PICOPAD_BASE_TOP_LEVEL_PROJECT)

    if (NOT PICOPAD_BASE_PATH)
        set(PICOPAD_BASE_PATH ${CMAKE_CURRENT_LIST_DIR})
    endif()
    set(PICOPAD_BASE_PATH "${PICOPAD_BASE_PATH}" CACHE PATH "Path to Pico Libs")

    # The real work gets done in post_init which is called at the end of pico_sdk_init
    list(APPEND PICO_SDK_POST_LIST_FILES ${CMAKE_CURRENT_LIST_DIR}/post_init.cmake)
    if (PICOPAD_BASE_TOP_LEVEL_PROJECT)
        message("picopad_base: initialize SDK since we're the top-level")
        # Initialize the SDK
        pico_sdk_init()
    else()
        set(PICO_SDK_POST_LIST_FILES ${PICO_SDK_POST_LIST_FILES} PARENT_SCOPE)
    endif()
endif()