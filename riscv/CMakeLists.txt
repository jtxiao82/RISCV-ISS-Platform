file(GLOB riscv_src main.cpp riscv_arch.cpp riscv_arch_ref.cpp riscv.cpp riscv_syscall.cpp riscv_intr_handlers.cpp *.H *.h)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()


# 2018/05/15
# Bug needs to be fixed
# Set the CMAKE FLAG here will cause the aspectC++ can't weave in riscv function. But remove these flags cause the compilation error which shows the inline function should never use "setjmp" and "goto"
# Sol:
#   Compilation error due to the aspectC++ file doesn't recognize the whole function among all class
#   So we should carefully assign the weaving
#set(CMAKE_CXX_FLAGS "-DAC_MATCH_ENDIANNESS  -Wno-deprecated -std=c++11")

#set(CMAKE_CXX_FLAGS "-DAC_MATCH_ENDIANNESS  -Wno-deprecated -std=c++11")

find_program(AGXX ag++ PATHS ~/tools/source/aspectc++ ENV PATH)
if(${AGXX} MATCHES "NOTFOUND")
  #message(FATAL_ERROR "ag++ not found.")
  set(CMAKE_CXX_FLAGS "-DAC_MATCH_ENDIANNESS  -Wno-deprecated -std=c++11")
else()
endif()


include_directories(${SYSTEMC_INCLUDE_DIRS})
include_directories(${ARCHC_INCLUDE_DIRS})

add_library(riscv ${riscv_src} ${ARCHC_INCLUDE_DIRS})

