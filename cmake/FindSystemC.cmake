#
# Try to find SystemC
# The following will be defined:
#   - SYSTEMC_FOUND 
#   - SYSTEMC_INCLUDE_DIRS
#   - SYSTEMC_LIBRARIES
#
# If SystemC is not installed in a standard path, 
# you can set environment variable SYSTEMC_HOME 
# to tell CMake where SystemC is.
#


set (SYSTEMC_SEARCH_PATH 
        /usr/local
        /usr
        #/home/jtxiao/NTHU/Research/Git/FI_Platform_Intrusive/FaultInjectionPlatform/install/systemc/
        ${CMAKE_CURRENT_SOURCE_DIR}/../../install/systemc
    )

find_path (SYSTEMC_INCLUDE_DIR systemc
    PATH_SUFFIXES include
    PATHS ${SYSTEMC_SEARCH_PATH}
    )

find_library (SYSTEMC_LIBRARY systemc
    PATH_SUFFIXES lib64 lib lib-macosx lib-macosx64 lib-linux64
    PATHS ${SYSTEMC_SEARCH_PATH}
    )

set(SYSTEMC_INCLUDE_DIRS ${SYSTEMC_INCLUDE_DIR})
set(SYSTEMC_LIBRARIES ${SYSTEMC_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SystemC DEFAULT_MSG SYSTEMC_INCLUDE_DIR SYSTEMC_LIBRARY)
mark_as_advanced(SYSTEMC_INCLUDE_DIR SYSTEMC_LIBRARY)

