/*
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */

#ifndef INCLUDED_ACACIA_FILE_INFO_H
#define INCLUDED_ACACIA_FILE_INFO_H

#include <stdint.h>
#include "acacia_status.h"
#include "acacia_context.h"

#ifdef __cpluscplus
extern "C" {
#endif

typedef struct {
    uint64_t size;
} acfs_file_info;

acfs_status_t 
acfs_read_file_info(acfs_ctx_t *ctx, 
                    acfs_file_info *info, 
                    const char *filepath);


#ifdef __cpluscplus
}
#endif

#endif /* INCLUDED_ACACIA_FILE_INFO_H */