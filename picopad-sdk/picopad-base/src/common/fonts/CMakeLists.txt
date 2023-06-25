if (NOT TARGET picopad_fonts_headers)
    add_library(picopad_fonts_headers INTERFACE)
    target_include_directories(picopad_fonts_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(picopad_fonts_headers INTERFACE pico_stdlib)
endif()

if (NOT TARGET picopad_fonts)
    add_library(picopad_fonts INTERFACE)

    target_sources(picopad_fonts INTERFACE

            )

    target_link_libraries(picopad_fonts INTERFACE picopad_fonts_headers)
endif()