cmake_minimum_required(VERSION 3.30)
project(diya_c C)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes
        -Wold-style-definition
)

add_library(diya_c STATIC diya.c)

