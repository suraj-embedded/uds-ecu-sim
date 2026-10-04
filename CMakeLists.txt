cmake_minimum_required(VERSION 3.16)
project(uds_ecu_sim C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Portable core: pure C, no OS calls -> ports to STM32 unchanged
add_library(uds_core STATIC core/uds_core.c)
target_include_directories(uds_core PUBLIC core)
target_compile_options(uds_core PRIVATE -Wall -Wextra -Wpedantic -Werror)

# Linux front-end: the only code allowed to touch the OS
add_executable(uds_server platform/linux/main.c)
target_link_libraries(uds_server PRIVATE uds_core)
target_compile_options(uds_server PRIVATE -Wall -Wextra -Wpedantic -Werror)
