/*
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */

#include "acacia_context.h"
#include "acacia_context_internal.h"

#include <stdlib.h>

acfs_status_t
acacia_context_create(acfs_ctx_t **ctx)
{
    acfs_status_t rv = ACFS_SUCCESS;
    acfs_ctx_t *_ctx = malloc(sizeof(acfs_ctx_t));
    if (!_ctx)
        return ACFS_MEM_ERROR;
    
    _ctx->loop = EV_DEFAULT;
    if (_ctx->loop) {
        rv = ACFS_EV_ERROR;
    }
    
    if (rv == ACFS_SUCCESS) {
        *ctx = _ctx;
    } else {
        free(_ctx);
    }
    return rv;
}

void
acacia_context_destroy(acfs_ctx_t *ctx)
{
    ev_loop_destroy(ctx->loop);
    free(ctx);
}

acfs_status_t
acacia_context_set_source(acfs_ctx_t *ctx, const char *host, int port)
{
    return ACFS_NETWORK_ERROR;
}