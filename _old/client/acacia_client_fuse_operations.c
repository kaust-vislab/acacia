/* 
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */

#include "acacia_client_fuse_operations.h"
#include <assert.h>

static inline acfs_ctx_t * get_acacia_context()
{
    struct fuse_context *fuse_ctx = fuse_get_context();
    assert(fuse_ctx);
    return (acfs_ctx_t *)fuse_ctx->private_data;
}

int 
acacia_client_read(const char *path, 
                   char *buf, 
                   size_t size, 
                   off_t offset,
                   struct fuse_file_info *fi)
{
    return 0;
}

int 
acacia_client_readdir(const char *path, 
                      void *buf, 
                      fuse_fill_dir_t filler,
                      off_t offset, 
                      struct fuse_file_info *fi)
{
    
    return 0;
}

int 
acacia_client_getattr(const char *path, struct stat *stbuf)
{
    
    return 0;
}

int 
acacia_client_open(const char *path, struct fuse_file_info *fi)
{
    
    return 0;
}

