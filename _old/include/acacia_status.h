/*  
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */

#ifndef INCLUDED_ACACIA_STATUS_H
#define INCLUDED_ACACIA_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ACFS_SUCCESS = 0,
    ACFS_FILE_ERROR,
    ACFS_MEM_ERROR,
    ACFS_THREAD_ERROR,
    ACFS_EV_ERROR,
    ACFS_NETWORK_ERROR
} acfs_status_t;

#ifdef __cplusplus
}
#endif

#endif /* INCLUDED_ACACIA_STATUS_H */