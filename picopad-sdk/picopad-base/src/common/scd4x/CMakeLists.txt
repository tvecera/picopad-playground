if (NOT TARGET scd4x_headers)
    add_library(scd4x_headers INTERFACE)
    target_include_directories(scd4x_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(scd4x_headers INTERFACE
            hardware_i2c
            )
endif()

if (NOT TARGET scd4x)
    add_library(scd4x INTERFACE)

    target_sources(scd4x INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/scd4x.cpp
    )

    target_link_libraries(scd4x INTERFACE scd4x_headers)
endif()
