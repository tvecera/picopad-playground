cmake_minimum_required(VERSION 3.13)

set(PICO_TOOLCHAIN_PATH /Applications/ARM)
set(PICO_SDK_PATH ../../../pico-sdk)
set(PICOPAD_BASE_PATH ../../../picopad-base)

set(CMAKE_SIZE ${PICO_TOOLCHAIN_PATH}/bin/arm-none-eabi-size)

include(pico_sdk_import.cmake)
include(picopad_base_import.cmake)

project(maze C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME} "src/main.cpp")

function(target_cl_options option)
    target_compile_options(${PROJECT_NAME} PRIVATE ${option})
    target_link_options(${PROJECT_NAME} PRIVATE ${option})
endfunction()

target_cl_options("-Os")
target_cl_options("-ffunction-sections")
target_cl_options("-fdata-sections")
target_link_options(${PROJECT_NAME} PRIVATE "LINKER:--gc-sections")

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-Wall")

pico_set_linker_script(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/memmap_default_noboot.ld)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(${PROJECT_NAME}
        pico_stdlib
        picopad
        picopad_libs
        picopad_sdk
        picopad_machine
        pico_divider
        )

pico_add_bin_output(${PROJECT_NAME})

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

# Create a 'build' directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

# Copy the .bin file to the 'build' directory after the build
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMENT "Copying bin file to build directory"
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME}.bin ${CMAKE_BINARY_DIR}/../build/${PROJECT_NAME_UPPER}.PP2
        )

file(COPY ${CMAKE_BINARY_DIR}/../assets/ DESTINATION ${CMAKE_BINARY_DIR}/../build/)

# Print the size of the binary file after the build is complete
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>)
