add_library(picopad_base_included INTERFACE)
target_compile_definitions(picopad_base_included INTERFACE
        -DPICOPAD_BASE=1
        )

pico_add_platform_library(picopad_base_included)

# note as we're a .cmake included by the SDK, we're relative to the pico-sdk build
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src ${CMAKE_BINARY_DIR}/picopad_base/src)

if (PICOPAD_BASE_TESTS_ENABLED OR PICOPAD_BASE_TOP_LEVEL_PROJECT)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test {CMAKE_BINARY_DIR}/picopad_base/test)
endif ()

