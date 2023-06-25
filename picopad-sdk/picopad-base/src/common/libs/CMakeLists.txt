if (NOT TARGET picopad_libs_headers)
    add_library(picopad_libs_headers INTERFACE)
    target_include_directories(picopad_libs_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(
            picopad_libs_headers INTERFACE
            picopad
            picopad_fonts
            picopad_st7789
            pico_stdlib
            cmsis_core
            hardware_gpio
            hardware_spi
            hardware_pwm
    )
endif()

if (NOT TARGET picopad_libs)
    add_library(picopad_libs INTERFACE)

    target_sources(picopad_libs INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/lib_calendar.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_color.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_crc.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_decnum.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_drawtft.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_fat.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_sd.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_list.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_print.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_stream.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_pwmsnd.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_text.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_textnum.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_rand.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_mat2d.c
            ${CMAKE_CURRENT_LIST_DIR}/lib_mem.c
    )

    target_link_libraries(picopad_libs INTERFACE picopad_libs_headers)
endif()
