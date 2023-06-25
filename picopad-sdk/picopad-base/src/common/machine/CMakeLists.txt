if (NOT TARGET picopad_machine_headers)
    add_library(picopad_machine_headers INTERFACE)
    target_include_directories(picopad_machine_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(
            picopad_machine_headers INTERFACE
            picopad
            picopad_st7789
            picopad_libs
            picopad_sdk
            pico_stdlib
            pico_unique_id
            pico_multicore
            hardware_gpio
            hardware_flash
    )
endif()

if (NOT TARGET picopad_machine)
    add_library(picopad_machine INTERFACE)

    target_sources(picopad_machine INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/picopad_bat.c
            ${CMAKE_CURRENT_LIST_DIR}/picopad_init.c
            ${CMAKE_CURRENT_LIST_DIR}/picopad_key.c
            ${CMAKE_CURRENT_LIST_DIR}/picopad_led.c
            ${CMAKE_CURRENT_LIST_DIR}/picopad_flash.c
            ${CMAKE_CURRENT_LIST_DIR}/picopad_pico_info.c
    )

    target_link_libraries(picopad_machine INTERFACE picopad_machine_headers)
endif()
