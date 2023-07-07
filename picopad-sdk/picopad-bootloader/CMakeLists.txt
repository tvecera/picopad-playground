cmake_minimum_required(VERSION 3.13)

#set(PICO_TOOLCHAIN_PATH /Applications/ARM)
set(PICO_TOOLCHAIN_PATH /usr)
set(PICO_SDK_PATH ../../pico-sdk)
set(PICOPAD_BASE_PATH ../../picopad-base)

set(CMAKE_SIZE ${PICO_TOOLCHAIN_PATH}/bin/arm-none-eabi-size)

include(pico_sdk_import.cmake)
include(picopad_base_import.cmake)

project(pico-bootloader C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

file(GLOB_RECURSE SOURCES "file-manager/src/*.cpp" "src/system_info.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} "src/main.cpp")

function(target_cl_options option)
    target_compile_options(${PROJECT_NAME} PRIVATE ${option})
    target_link_options(${PROJECT_NAME} PRIVATE ${option})
endfunction()

target_cl_options("-Os")
target_cl_options("-ffunction-sections")
target_cl_options("-fdata-sections")
target_link_options(${PROJECT_NAME} PRIVATE "LINKER:--gc-sections")

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-Wall")

pico_add_extra_outputs(${PROJECT_NAME})

pico_set_linker_script(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/ld/bootloader.ld)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(pico-bootloader
        pico_stdlib
        cmsis_core
        picopad
        picopad_fonts
        picopad_st7789
        picopad_libs
        picopad_machine
        picopad_sdk
        pico_divider
        )

# Create a 'build' directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

# Copy the .elf, .bin, and .hex files to the 'build' directory after the build
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMENT "Copying elf file to build directory"
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME}.elf ${CMAKE_BINARY_DIR}/../build/
        COMMENT "Copying bin file to build directory"
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME}.bin ${CMAKE_BINARY_DIR}/../build/
        COMMENT "Copying hex file to build directory"
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME}.hex ${CMAKE_BINARY_DIR}/../build/
        COMMENT "Copying uf2 file to build directory"
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME}.uf2 ${CMAKE_BINARY_DIR}/../build/
        )

file(COPY ${CMAKE_BINARY_DIR}/../assets/ DESTINATION ${CMAKE_BINARY_DIR}/../build/)

# Print the size of the binary file after the build is complete
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>)
