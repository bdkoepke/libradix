cmake_minimum_required(VERSION 2.8)
########### next target ###############
set(libradix_C
    maybe.c
    main.c)

add_executable(radix ${libradix_C})
