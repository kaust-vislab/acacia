# - Find LIBEV library
# Find the native LIBEV includes and library
# This module defines
#  LIBEV_INCLUDE_DIR, where to find msgpack.h, etc.
#  LIBEV_LIBRARIES, libraries to link against to use LIBEV.
#  LIBEV_FOUND, If false, do not try to use LIBEV.
# also defined, but not for general use are
#  LIBEV_LIBRARY, where to find the LIBEV library.

FIND_PATH(LIBEV_INCLUDE_DIR ev.h)

SET(LIBEV_NAMES ${LIBEV_NAMES} ev)
FIND_LIBRARY(LIBEV_LIBRARY NAMES ${LIBEV_NAMES} )

# IF(LIBEV_INCLUDE_DIR AND EXISTS "${LIBEV_INCLUDE_DIR}/tiffvers.h")
#     FILE(STRINGS "${LIBEV_INCLUDE_DIR}/tiffvers.h" tiff_version_str
#          REGEX "^#define[\t ]+LIBEVLIB_VERSION_STR[\t ]+\"LIBLIBEV, Version .*")
# 
#     STRING(REGEX REPLACE "^#define[\t ]+LIBEVLIB_VERSION_STR[\t ]+\"LIBLIBEV, Version +([^ \\n]*).*"
#            "\\1" LIBEV_VERSION_STRING "${tiff_version_str}")
#     UNSET(tiff_version_str)
# ENDIF()

# handle the QUIETLY and REQUIRED arguments and set LIBEV_FOUND to TRUE if 
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LIBEV
                                  REQUIRED_VARS LIBEV_LIBRARY LIBEV_INCLUDE_DIR
                                  VERSION_VAR LIBEV_VERSION_STRING)

IF(LIBEV_FOUND)
  SET( LIBEV_LIBRARIES ${LIBEV_LIBRARY} )
ENDIF(LIBEV_FOUND)

MARK_AS_ADVANCED(LIBEV_INCLUDE_DIR LIBEV_LIBRARY)
