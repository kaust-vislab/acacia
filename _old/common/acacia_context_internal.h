/* 
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */


#ifndef INCLUDED_ACACIA_CONTEXT_INTERNAL_H
#define INCLUDED_ACACIA_CONTEXT_INTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ev.h"

struct acacia_context 
{
    struct ev_loop *loop;
};
    
#ifdef __cplusplus
}
#endif


#endif /* INCLUDED_ACACIA_CONTEXT_INTERNAL_H */