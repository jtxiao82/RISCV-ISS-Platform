file(GLOB bus_src *.cpp *.cc *.h *.H)

find_program(AGXX ag++ PATHS ~/tools/source/aspectc++ ENV PATH)
if(${AGXX} MATCHES "NOTFOUND")
  #message(FATAL_ERROR "ag++ not found.")
  set(CMAKE_CXX_FLAGS "-DAC_MATCH_ENDIANNESS  -Wno-deprecated -std=c++11")
else()
endif()

include_directories(${SYSTEMC_INCLUDE_DIRS})
include_directories(${ARCHC_INCLUDE_DIRS})

add_library(bus ${bus_src} ${ARCHC_INCLUDE_DIRS})
