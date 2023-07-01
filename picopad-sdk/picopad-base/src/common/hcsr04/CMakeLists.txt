if (NOT TARGET hcsr04_headers)
    add_library(hcsr04_headers INTERFACE)

    pico_generate_pio_header(hcsr04_headers ${CMAKE_CURRENT_LIST_DIR}/hcsr04.pio)

    target_include_directories(hcsr04_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(hcsr04_headers INTERFACE
            hardware_pio
            )
endif ()

if (NOT TARGET hcsr04)
    add_library(hcsr04 INTERFACE)
    target_sources(hcsr04 INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/hcsr04.cpp
            )

    target_link_libraries(hcsr04 INTERFACE hcsr04_headers)
endif ()
