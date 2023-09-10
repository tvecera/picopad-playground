# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Development/sdk/pico/pico-sdk/tools/pioasm"
  "C:/Development/sdk/netczech/picopad-playground/picopad-sdk/picopad-gb/build/pioasm"
  "C:/Development/sdk/netczech/picopad-playground/picopad-sdk/picopad-gb/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "C:/Development/sdk/netczech/picopad-playground/picopad-sdk/picopad-gb/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "C:/Development/sdk/netczech/picopad-playground/picopad-sdk/picopad-gb/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "C:/Development/sdk/netczech/picopad-playground/picopad-sdk/picopad-gb/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "C:/Development/sdk/netczech/picopad-playground/picopad-sdk/picopad-gb/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Development/sdk/netczech/picopad-playground/picopad-sdk/picopad-gb/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Development/sdk/netczech/picopad-playground/picopad-sdk/picopad-gb/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
