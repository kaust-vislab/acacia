/*
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */


#ifndef INCLUDED_ACACIA_CLIENT_FUSE_OPERATIONS_H
#define INCLUDED_ACACIA_CLIENT_FUSE_OPERATIONS_H

#include "acacia.h"

#define FUSE_USE_VERSION 26
#include <fuse.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    
int 
acacia_client_read(const char *path, 
                 char *buf, 
                 size_t size, 
                 off_t offset,
                 struct fuse_file_info *fi);

int 
acacia_client_readdir(const char *path, 
                    void *buf, 
                    fuse_fill_dir_t filler,
                    off_t offset, 
                    struct fuse_file_info *fi);

int 
acacia_client_getattr(const char *path, struct stat *stbuf);

int 
acacia_client_open(const char *path, struct fuse_file_info *fi);

    
#ifdef __cplusplus
}
#endif


#endif /* INCLUDED_ACACIA_CLIENT_FUSE_OPERATIONS_H */