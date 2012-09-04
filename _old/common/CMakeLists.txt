set (SOURCES
	acacia_context.c
	acacia_file_info.c
)

set (INTERFACE_HEADERS
	${ACACIA_INTERFACE_DIR}/acacia.h
	${ACACIA_INTERFACE_DIR}/acacia_status.h
	${ACACIA_INTERFACE_DIR}/acacia_context.h
	${ACACIA_INTERFACE_DIR}/acacia_file_info.h
)

set (INTERNAL_HEADERS
    acacia_context_internal.h
)

add_library(acacia_common STATIC 
            ${SOURCES}
            ${INTERFACE_HEADERS}
            ${INTERNAL_HEADERS})

acacia_test(acacia_file_info_test acacia_common)
