# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

include(../cmake/add-enclave.cmake)

add_custom_command(
  OUTPUT
    EnclaveFibonacci_t.h
    EnclaveFibonacci_t.c
    EnclaveFibonacci_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/EnclaveFibonacci.edl
  COMMAND openenclave::oeedger8r --trusted ${CMAKE_SOURCE_DIR}/EnclaveFibonacci.edl)

add_enclave(
  TARGET EnclaveFibonacci_enclave
  UUID 5d286b7e-ff68-4b4b-b7b8-05f55dbfd0c7
    SOURCES
    enc.c
    ${CMAKE_CURRENT_BINARY_DIR}/EnclaveFibonacci_t.c)
