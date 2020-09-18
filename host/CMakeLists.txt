# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

add_custom_command(
  OUTPUT
    EnclaveFibonacci_u.h
    EnclaveFibonacci_u.c
    EnclaveFibonacci_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/EnclaveFibonacci.edl
  COMMAND openenclave::oeedger8r --untrusted ${CMAKE_SOURCE_DIR}/EnclaveFibonacci.edl)

add_executable(EnclaveFibonacci
    host.c
    main.c
    ${CMAKE_CURRENT_BINARY_DIR}/EnclaveFibonacci_u.c)

target_include_directories(EnclaveFibonacci PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(EnclaveFibonacci openenclave::oehost)
