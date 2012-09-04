set (SOURCES
	acacia_client.c
    acacia_client_fuse_operations.c
)

set (HEADERS
    acacia_client_fuse_operations.h
)

include_directories(
    ${FUSE_INCLUDE_DIR}
)

add_definitions(-D_FILE_OFFSET_BITS=64)
add_executable(acacia_cient ${SOURCES} ${HEADERS})
target_link_libraries(acacia_cient 
    ${ACACIA_LINK_LIBS} 
    ${FUSE_LIBRARIES}
    acacia_common
)

acacia_test(acacia_client_test acacia_common)