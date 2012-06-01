/*
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */

#ifndef INCLUDED_ACACIA_CONTEXT_H
#define INCLUDED_ACACIA_CONTEXT_H

#include "acacia_status.h"

#ifdef __cplusplus
extern "C" {
#endif

/* opaque context */
typedef struct acacia_context acfs_ctx_t;
    
acfs_status_t
acacia_context_create(acfs_ctx_t **ctx);
    
void
acacia_context_destroy(acfs_ctx_t *ctx);

acfs_status_t
acacia_context_set_source(acfs_ctx_t *ctx, const char *host, int port);

#ifdef __cplusplus
}
#endif


#endif /* INCLUDED_ACACIA_CONTEXT_H */
