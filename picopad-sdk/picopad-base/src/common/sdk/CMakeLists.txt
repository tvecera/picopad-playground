if (NOT TARGET picopad_sdk_headers)
    add_library(picopad_sdk_headers INTERFACE)
    target_include_directories(picopad_sdk_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(
            picopad_sdk_headers INTERFACE
            picopad
            pico_stdlib
            hardware_gpio
            hardware_adc
            hardware_watchdog
            hardware_sync
    )
endif ()

if (NOT TARGET picopad_sdk)
    add_library(picopad_sdk INTERFACE)

    target_sources(picopad_sdk INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/sdk_adc.c
            ${CMAKE_CURRENT_LIST_DIR}/sdk_watchdog.c
            ${CMAKE_CURRENT_LIST_DIR}/sdk_flash.c
            ${CMAKE_CURRENT_LIST_DIR}/sdk_config.c
            ${CMAKE_CURRENT_LIST_DIR}/sdk_cpu.c
            )

    target_link_libraries(picopad_sdk INTERFACE picopad_sdk_headers)
endif ()
