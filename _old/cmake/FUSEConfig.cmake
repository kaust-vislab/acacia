# - Find FUSE library
# Find the native FUSE includes and library
# This module defines
#  FUSE_INCLUDE_DIR, where to find msgpack.h, etc.
#  FUSE_LIBRARIES, libraries to link against to use FUSE.
#  FUSE_FOUND, If false, do not try to use FUSE.
# also defined, but not for general use are
#  FUSE_LIBRARY, where to find the FUSE library.

FIND_PATH(FUSE_INCLUDE_DIR fuse.h)

SET(FUSE_NAMES ${FUSE_NAMES} fuse4x fuse)
FIND_LIBRARY(FUSE_LIBRARY NAMES ${FUSE_NAMES} )

# IF(FUSE_INCLUDE_DIR AND EXISTS "${FUSE_INCLUDE_DIR}/tiffvers.h")
#     FILE(STRINGS "${FUSE_INCLUDE_DIR}/tiffvers.h" tiff_version_str
#          REGEX "^#define[\t ]+FUSELIB_VERSION_STR[\t ]+\"LIBFUSE, Version .*")
# 
#     STRING(REGEX REPLACE "^#define[\t ]+FUSELIB_VERSION_STR[\t ]+\"LIBFUSE, Version +([^ \\n]*).*"
#            "\\1" FUSE_VERSION_STRING "${tiff_version_str}")
#     UNSET(tiff_version_str)
# ENDIF()

# handle the QUIETLY and REQUIRED arguments and set FUSE_FOUND to TRUE if 
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FUSE
                                  REQUIRED_VARS FUSE_LIBRARY FUSE_INCLUDE_DIR
                                  VERSION_VAR FUSE_VERSION_STRING)

IF(FUSE_FOUND)
  SET( FUSE_LIBRARIES ${FUSE_LIBRARY} )
ENDIF(FUSE_FOUND)

MARK_AS_ADVANCED(FUSE_INCLUDE_DIR FUSE_LIBRARY)
