/*
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */

#include "acacia_file_info.h"
#include <sys/stat.h>

acfs_status_t 
acfs_read_file_info(acfs_ctx_t *ctx,
                    acfs_file_info *info, 
                    const char *filepath)
{
    struct stat file_stats;
    
    if (stat(filepath, &file_stats) < 0) {
        return ACFS_FILE_ERROR;
    }
    info->size = file_stats.st_size;
    return ACFS_SUCCESS;
}
