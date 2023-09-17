if (NOT TARGET sht4x_headers)
    add_library(sht4x_headers INTERFACE)
    target_include_directories(sht4x_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(sht4x_headers INTERFACE
            hardware_i2c
            )
endif()

if (NOT TARGET sht4x)
    add_library(sht4x INTERFACE)

    target_sources(sht4x INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/sht4x.cpp
    )

    target_link_libraries(sht4x INTERFACE sht4x_headers)
endif()
