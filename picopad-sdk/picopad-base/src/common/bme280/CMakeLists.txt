if (NOT TARGET bme280_headers)
    add_library(bme280_headers INTERFACE)
    target_include_directories(bme280_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(bme280_headers INTERFACE
            hardware_i2c
            )
endif()

if (NOT TARGET bme280)
    add_library(bme280 INTERFACE)

    target_sources(bme280 INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/bme280.cpp
    )

    target_link_libraries(bme280 INTERFACE bme280_headers)
endif()
