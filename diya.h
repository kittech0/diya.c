#ifndef DIYAC_H
#define DIYAC_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// String

typedef uint8_t diya_str_raw_t;

typedef struct {
    //TODO: bool heap;
    size_t length;
    diya_str_raw_t* value;
} diya_str_t;

/**
 * Used to initialize the string
 * @param string the string
**/
diya_str_t diya_str_new(diya_str_raw_t* string);
bool diya_str_equal(diya_str_t str1, diya_str_t str2);

/// String


/// Result

typedef enum {
    err,
    ok
} diya_result_type_t;

/// TODO: make own result type generator
// #define diya_result_new_t(type) typedef struct {\
// diya_result_type_t type;\
// union {\
//     const diya_str_t err;\
//     type ok;\
// } value;\
// } diya_result_type_t;

typedef struct {
    diya_result_type_t type;

    union {\
        const diya_str_t err;
        void* ok;
    } value;
} diya_result_t;


diya_result_t diya_result_error(diya_str_t err_message);

diya_result_t diya_result_ok(void* ok_value);

#define diya_result_unwrap(type_, variable, result) \
if ((result).type != ok) { \
printf("[ERR] diya_result_unwrap: value is error\n"); \
exit(1); \
} else { \
variable = (type_*) (result).value.ok; \
}

/// Result

///TODO: Arena allocator


///TODO: Arena allocator

/// Logger TODO
typedef enum {
    silent,
    error,
    warn,
    log,
    info,
    debug,
} diya_logger_level_t;

typedef struct {
    diya_str_t name;
    diya_logger_level_t level;
} diya_logger_t;


void diya_logger_warn(diya_logger_t* logger, diya_str_t value); //TODO: make it run

/// Logger

#endif
