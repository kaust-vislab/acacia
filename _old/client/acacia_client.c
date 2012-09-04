/* 
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */


#include "acacia.h"
#include "acacia_client_fuse_operations.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    const char *host;
    int port;
} prog_args;

typedef struct {
    prog_args args;
    acfs_ctx_t *acfs_ctx;
} filectx;

static void parse_args(prog_args *args, int argc, char **argv)
{
    int i;
    for (i = 0; i != argc; ++i) {
        if (!args->host && strncmp("--host=", argv[i], 7) == 0 &&
            strlen(argv[i]) > 7) {
            args->host = argv[i] + 7;
        }
        else if (!args->port && 
                 strncmp("--port=", argv[i], 7) == 0 &&
                 strlen(argv[i]) > 7) {
            args->port = atoi(argv[i] + 7);
        }
    }
}

static struct fuse_operations acacia_client_oper = {
    .getattr    = acacia_client_getattr,
    .readdir    = acacia_client_readdir,
    .open       = acacia_client_open,
    .read       = acacia_client_read,
};


int main(int argc, char **argv)
{
    filectx ctx = {{0}};
    parse_args(&ctx.args, argc, argv);
    
    if (acacia_context_create(&ctx.acfs_ctx) != ACFS_SUCCESS)
        return EXIT_FAILURE;
    
    return fuse_main(argc, argv, &acacia_client_oper, (void*)ctx.acfs_ctx);    
}
