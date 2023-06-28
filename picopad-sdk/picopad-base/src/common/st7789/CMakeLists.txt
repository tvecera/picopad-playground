if (NOT TARGET picopad_st7789_headers)
    add_library(picopad_st7789_headers INTERFACE)
    target_include_directories(picopad_st7789_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(
            picopad_st7789_headers INTERFACE
            picopad
            picopad_sdk
            pico_stdlib
            hardware_gpio
            hardware_spi
    )
endif()

if (NOT TARGET picopad_st7789)
    add_library(picopad_st7789 INTERFACE)

    target_sources(picopad_st7789 INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/st7789.c
    )

    target_link_libraries(picopad_st7789 INTERFACE picopad_st7789_headers)
endif()
