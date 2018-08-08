file(GLOB platform_src *.cpp *.h *.cc)

add_executable(platform ${platform_src})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-std=c++11  -DAC_GUEST_BIG_ENDIAN  -Wno-deprecated")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O1")

include_directories(${SYSTEMC_INCLUDE_DIRS})
include_directories(${ARCHC_INCLUDE_DIRS})

# hard code to import archC lib
add_library(archc SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(archc PROPERTIES
  IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../../../install/archc/lib/libarchc.a"
)



target_link_libraries(platform 
    riscv
    bus
    memory
    archc
    fi_lib
    monitor
    tinyxml
    ${SYSTEMC_LIBRARIES} 
    ${ARCHC_LIBRARIES} 
    )

