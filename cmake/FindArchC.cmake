#
# Try to find SystemC
# The following will be defined:
#   - ARCHC_FOUND 
#   - ARCHC_INCLUDE_DIRS
#   - ARCHC_LIBRARIES
#
# If SystemC is not installed in a standard path, 
# you can set environment variable ARCHC_HOME 
# to tell CMake where SystemC is.
#

# Hard code the ARCHC install path
set (ARCHC_SEARCH_PATH 
        /usr/local
        /usr
        ${CMAKE_CURRENT_SOURCE_DIR}/../../install/archc
    )

# Hard code the ARCHC include path
set (ARCHC_INCLUDE_DIR

        ${CMAKE_CURRENT_SOURCE_DIR}/../../install/archc/include
        ${CMAKE_CURRENT_SOURCE_DIR}/fi_lib
        ${CMAKE_CURRENT_SOURCE_DIR}/monitor
        ${CMAKE_CURRENT_SOURCE_DIR}/tinyxml
    )

find_path (ARCHC_INCLUDE_DIR archc
    PATH_SUFFIXES include
    PATHS ${ARCHC_SEARCH_PATH}
    )

set (ARCHC_LIBRARY
        ${CMAKE_CURRENT_SOURCE_DIR}/../../install/archc/lib
    )

find_library (ARCHC_LIBRARY archc
    PATH_SUFFIXES lib 
    PATHS ${ARCHC_SEARCH_PATH}
    )

set(ARCHC_INCLUDE_DIRS ${ARCHC_INCLUDE_DIR})
set(ARCHC_LIBRARIES ${ARCHC_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ArchC DEFAULT_MSG ARCHC_INCLUDE_DIR ARCHC_LIBRARY)
mark_as_advanced(ARCHC_INCLUDE_DIR ARCHC_LIBRARY)

