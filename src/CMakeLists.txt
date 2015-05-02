cmake_minimum_required(VERSION 2.8)
########### next target ###############
set(libradix_C
    contract.c
    cstring.c
    hexdump.c
    main.c
    maybe.c
    radix.c)

add_executable(radix ${libradix_C})
