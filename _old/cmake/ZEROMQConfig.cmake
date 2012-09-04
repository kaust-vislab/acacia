# - Find ZEROMQ library
# Find the native ZEROMQ includes and library
# This module defines
#  ZEROMQ_INCLUDE_DIR, where to find tiff.h, etc.
#  ZEROMQ_LIBRARIES, libraries to link against to use ZEROMQ.
#  ZEROMQ_FOUND, If false, do not try to use ZEROMQ.
# also defined, but not for general use are
#  ZEROMQ_LIBRARY, where to find the ZEROMQ library.

FIND_PATH(ZEROMQ_INCLUDE_DIR zmq.h)

SET(ZEROMQ_NAMES ${ZEROMQ_NAMES} zmq)
FIND_LIBRARY(ZEROMQ_LIBRARY NAMES ${ZEROMQ_NAMES} )

# IF(ZEROMQ_INCLUDE_DIR AND EXISTS "${ZEROMQ_INCLUDE_DIR}/tiffvers.h")
#     FILE(STRINGS "${ZEROMQ_INCLUDE_DIR}/tiffvers.h" tiff_version_str
#          REGEX "^#define[\t ]+ZEROMQLIB_VERSION_STR[\t ]+\"LIBZEROMQ, Version .*")
# 
#     STRING(REGEX REPLACE "^#define[\t ]+ZEROMQLIB_VERSION_STR[\t ]+\"LIBZEROMQ, Version +([^ \\n]*).*"
#            "\\1" ZEROMQ_VERSION_STRING "${tiff_version_str}")
#     UNSET(tiff_version_str)
# ENDIF()

# handle the QUIETLY and REQUIRED arguments and set ZEROMQ_FOUND to TRUE if 
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ZEROMQ
                                  REQUIRED_VARS ZEROMQ_LIBRARY ZEROMQ_INCLUDE_DIR
                                  VERSION_VAR ZEROMQ_VERSION_STRING)

IF(ZEROMQ_FOUND)
  SET( ZEROMQ_LIBRARIES ${ZEROMQ_LIBRARY} )
ENDIF(ZEROMQ_FOUND)

MARK_AS_ADVANCED(ZEROMQ_INCLUDE_DIR ZEROMQ_LIBRARY)
