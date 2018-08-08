cmake_minimum_required(VERSION 3.4.3)
project(FaultInjectionPlatform)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# activate ctest
enable_testing()

# Run simulation script
configure_file(script/runFaultFreeSim.sh runFaultFreeSim.sh COPYONLY)
configure_file(script/runFaultSim.sh runFaultSim.sh COPYONLY)
configure_file(script/genFaultList.py genFaultList.py COPYONLY)
configure_file(script/getRTLCycleTable.sh getRTLCycleTable.sh COPYONLY)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SystemC)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
find_package(ArchC)

#include(FindCompiler)

add_subdirectory(riscv)
include_directories(riscv)

add_subdirectory(bus)
include_directories(bus)

add_subdirectory(memory)
include_directories(memory)

add_subdirectory(monitor)
include_directories(monitor)

add_subdirectory(platform)
