/*
 * Copyright 2012. All rights reserved
 * Christopher Knox
 * Visualization Laboratory
 * King Abdullah University of Science and Technology
 */

#include "acacia_file_info.h"

#include <stdlib.h>
#define CTEST_MAIN
#include "ctest.h"

// TODO: put this in the test data
static const char *exename = NULL;

CTEST_DATA(file_info) {
    acfs_ctx_t *ctx;
};

CTEST_SETUP(file_info) {
    acfs_status_t s = acacia_context_create(&data->ctx);
    ASSERT_EQUAL(s, ACFS_SUCCESS);
}

CTEST2(file_info, read_non_file) {
    acfs_file_info info;
    acfs_status_t s = acfs_read_file_info(data->ctx, &info, "NOFILE");
    ASSERT_EQUAL(s, ACFS_FILE_ERROR);
}

CTEST2(file_info, read_this_exe) {
    acfs_file_info info;
    acfs_status_t s = acfs_read_file_info(data->ctx, &info, exename);
    ASSERT_EQUAL(s, ACFS_SUCCESS);	
}

int main(int argc, const char **argv)
{
	exename = argv[0];
	return ctest_main(argc, argv); 
}