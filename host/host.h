// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#define ENCLAVE_MESSAGE_SIZE 512

int create_enclave(int argc, const char* argv[]);
int terminate_enclave();
int call_enclave(
    int *arr,
    unsigned int count);
