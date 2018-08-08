cmake_minimum_required(VERSION 3.4.3)
project(FaultInjectionPlatform)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# activate ctest
enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SystemC)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
find_package(ArchC)

add_subdirectory(riscv)
include_directories(riscv)

add_subdirectory(bus)
include_directories(bus)

add_subdirectory(memory)
include_directories(memory)

add_subdirectory(platform)
