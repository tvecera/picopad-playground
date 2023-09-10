# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.26

# compile ASM with C:/Development/arm-none-eabi/bin/arm-none-eabi-gcc.exe
# compile C with C:/Development/arm-none-eabi/bin/arm-none-eabi-gcc.exe
# compile CXX with C:/Development/arm-none-eabi/bin/arm-none-eabi-g++.exe
ASM_DEFINES = -DLIB_CMSIS_CORE=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_MULTICORE=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RAND=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICOPAD_BASE=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0

ASM_INCLUDES = -IC:\Development\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_base\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\applications\ds18b20\build\generated\pico_base -IC:\Development\sdk\pico\pico-sdk\src\boards\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\Development\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\Development\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_uart\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_mem_ops\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\picopad\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_rand\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_flash\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_spi\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_dma\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\libs\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\fonts\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\st7789\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\sdk\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_adc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\cmsis\stub\CMSIS\Core\Include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\cmsis\stub\CMSIS\Device\RaspberryPi\RP2040\Include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_pwm\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\machine\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_multicore\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\vendor\pico-onewire\api

ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g -Wall -Os -ffunction-sections -fdata-sections

C_DEFINES = -DLIB_CMSIS_CORE=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_MULTICORE=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RAND=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICOPAD_BASE=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0

C_INCLUDES = -IC:\Development\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_base\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\applications\ds18b20\build\generated\pico_base -IC:\Development\sdk\pico\pico-sdk\src\boards\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\Development\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\Development\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_uart\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_mem_ops\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\picopad\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_rand\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_flash\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_spi\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_dma\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\libs\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\fonts\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\st7789\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\sdk\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_adc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\cmsis\stub\CMSIS\Core\Include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\cmsis\stub\CMSIS\Device\RaspberryPi\RP2040\Include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_pwm\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\machine\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_multicore\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\vendor\pico-onewire\api

C_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g -std=gnu11 -Wall -Os -ffunction-sections -fdata-sections

CXX_DEFINES = -DLIB_CMSIS_CORE=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_MULTICORE=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RAND=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICOPAD_BASE=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0

CXX_INCLUDES = -IC:\Development\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_base\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\applications\ds18b20\build\generated\pico_base -IC:\Development\sdk\pico\pico-sdk\src\boards\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\Development\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\Development\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\Development\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_uart\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_mem_ops\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\picopad\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_rand\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_flash\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_spi\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_dma\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\libs\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\fonts\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\st7789\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\sdk\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_adc\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\cmsis\stub\CMSIS\Core\Include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\cmsis\stub\CMSIS\Device\RaspberryPi\RP2040\Include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\hardware_pwm\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\common\machine\include -IC:\Development\sdk\pico\pico-sdk\src\rp2_common\pico_multicore\include -IC:\Development\sdk\netczech\picopad-playground\picopad-sdk\picopad-base\src\vendor\pico-onewire\api

CXX_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g -std=gnu++17 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-unwind-tables -fno-rtti -fno-use-cxa-atexit

