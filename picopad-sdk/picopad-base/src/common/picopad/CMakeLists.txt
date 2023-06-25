if (NOT TARGET picopad_headers)
    add_library(picopad_headers INTERFACE)
    target_include_directories(picopad_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(
            picopad_headers INTERFACE
            pico_stdlib
            pico_rand
            hardware_spi
            hardware_dma
    )
endif()

if (NOT TARGET picopad)
    add_library(picopad INTERFACE)

    target_sources(picopad INTERFACE

            )

    target_link_libraries(picopad INTERFACE picopad_headers)
endif()
