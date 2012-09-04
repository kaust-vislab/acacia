# - Find MSGPACK library
# Find the native MSGPACK includes and library
# This module defines
#  MSGPACK_INCLUDE_DIR, where to find msgpack.h, etc.
#  MSGPACK_LIBRARIES, libraries to link against to use MSGPACK.
#  MSGPACK_FOUND, If false, do not try to use MSGPACK.
# also defined, but not for general use are
#  MSGPACK_LIBRARY, where to find the MSGPACK library.

FIND_PATH(MSGPACK_INCLUDE_DIR msgpack.h)

SET(MSGPACK_NAMES ${MSGPACK_NAMES} msgpackc)
FIND_LIBRARY(MSGPACK_LIBRARY NAMES ${MSGPACK_NAMES} )

# IF(MSGPACK_INCLUDE_DIR AND EXISTS "${MSGPACK_INCLUDE_DIR}/tiffvers.h")
#     FILE(STRINGS "${MSGPACK_INCLUDE_DIR}/tiffvers.h" tiff_version_str
#          REGEX "^#define[\t ]+MSGPACKLIB_VERSION_STR[\t ]+\"LIBMSGPACK, Version .*")
# 
#     STRING(REGEX REPLACE "^#define[\t ]+MSGPACKLIB_VERSION_STR[\t ]+\"LIBMSGPACK, Version +([^ \\n]*).*"
#            "\\1" MSGPACK_VERSION_STRING "${tiff_version_str}")
#     UNSET(tiff_version_str)
# ENDIF()

# handle the QUIETLY and REQUIRED arguments and set MSGPACK_FOUND to TRUE if 
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(MSGPACK
                                  REQUIRED_VARS MSGPACK_LIBRARY MSGPACK_INCLUDE_DIR
                                  VERSION_VAR MSGPACK_VERSION_STRING)

IF(MSGPACK_FOUND)
  SET( MSGPACK_LIBRARIES ${MSGPACK_LIBRARY} )
ENDIF(MSGPACK_FOUND)

MARK_AS_ADVANCED(MSGPACK_INCLUDE_DIR MSGPACK_LIBRARY)
