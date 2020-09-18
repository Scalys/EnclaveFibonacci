// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "host.h"

int main(int argc, const char* argv[])
{
    int result = create_enclave(argc, argv);
    if (result != 0)
    {
        fprintf(stderr, "Failed to create enclave with result = %i.\n", result);

        return result;
    }

    int count = 64;
    int *fib = calloc(count, sizeof(int));

    if (fib == NULL)
    {
        fprintf(stderr, "Failed to allocate memory.\n");

        terminate_enclave();
        return ENOMEM;
    }

    result = call_enclave(fib, count);
    if (result != 0)
    {
        fprintf(stderr, "Failed to call enclave with result = %i.\n", result);

        terminate_enclave();
        return result;
    }

    for (size_t i = 0; i < count; ++i) {
        fprintf(stdout, "%d%c", fib[i], " \n"[i == count - 1]);
    }

    result = terminate_enclave();
    if (result != 0)
    {
        fprintf(
            stderr, "Failed to terminate enclave with result = %i.\n", result);
    }

    return result;
}
