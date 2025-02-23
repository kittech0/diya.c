cmake_minimum_required(VERSION 3.30)
project(diya_c C)

set(CMAKE_C_STANDARD 23)

# Common compile options
add_compile_options(-Wall -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes
        -Wold-style-definition)

# Create diya_c library
add_library(diya_c SHARED src/diya.c)

# Create test executable
add_executable(diya_test_c src/diya.c src/diya.test.c)

# Set compile options for different build-debug types
target_compile_options(diya_c PRIVATE
        $<$<CONFIG:Debug>:-g -O0 -DDEBUG>  # Debug: Enable debug symbols, no optimization
        $<$<CONFIG:Release>:-O2 -DNDEBUG>  # Release: Optimization, no debug
)

target_compile_options(diya_test_c PRIVATE
        $<$<CONFIG:Debug>:-g -O0 -DDEBUG>
        $<$<CONFIG:Release>:-O3 -DNDEBUG>
)
