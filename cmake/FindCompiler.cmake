set(CMAKE_C_FLAGS "-g -Wno-unused-local-typedefs")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fno-inline-small-functions -DAC_GUEST_BIG_ENDIAN  -Wno-deprecated -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-gc-sections")

set(CMAKE_C_COMPILER "gcc")
find_program(AGXX ag++ PATHS ~/tools/source/aspectc++ ENV PATH)
if(${AGXX} MATCHES "NOTFOUND")
  #message(FATAL_ERROR "ag++ not found.")
  set(CMAKE_CXX_COMPILER "g++")
  set(CMAKE_CXX_FLAGS "" CACHE STRING "Additional ag++ flags (space-separated), e.g., --keep_woven")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -p ${PROJECT_SOURCE_DIR}/riscv -p ${PROJECT_SOURCE_DIR}/bus -p ${PROJECT_SOURCE_DIR}/memory -p ${PROJECT_SOURCE_DIR}/fi_lib -p ${PROJECT_BINARY_DIR}/platform ${CMAKE_CXX_FLAGS}")
else()
  set(CMAKE_CXX_COMPILER "${AGXX}")
  set(CMAKE_AGPP_FLAGS "" CACHE STRING "Additional ag++ flags (space-separated), e.g., --keep_woven")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --Xweaver -p ${PROJECT_SOURCE_DIR}/riscv -p ${PROJECT_SOURCE_DIR}/bus -p ${PROJECT_SOURCE_DIR}/memory -p ${PROJECT_SOURCE_DIR}/fi_lib -p ${PROJECT_BINARY_DIR}/platform ${CMAKE_AGPP_FLAGS} --Xcompiler")
endif()



#add_definitions(-D_FILE_OFFSET_BITS=64)

message(STATUS "[${PROJECT_NAME}] Compiler: ${CMAKE_C_COMPILER} + ${CMAKE_CXX_COMPILER}" )
