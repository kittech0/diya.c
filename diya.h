#ifndef DIYAC_H
#define DIYAC_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/// String

typedef uint8_t* diya_RawString;

typedef struct {
    size_t length;
    diya_RawString value;
} diya_String;

inline diya_String diya_String_new(diya_RawString str) {
    const size_t length = sizeof(str) - 1;
    const diya_String diya_str = {
        .value = str,
        .length = length
    };
    return diya_str;
}

inline bool diya_String_equal(diya_String str1, diya_String str2) {
    if (str1.length != str2.length) return false;
    for (int i = 0; i < str1.length; i++) {
        if (str1.value[i] != str2.value[i]) return false;
    }
    return true;
}

/// String


/// Result

typedef enum {
    Error,
    Ok
} diya_ResultType;

typedef struct {
    diya_ResultType type;

    union {\
        const diya_String err;
        void* ok;
    } value;
} diya_Result;


inline diya_Result diya_Result_error(diya_String err_message) {
    return (diya_Result){
        .type = Error,
        .value.err = err_message
    };
}

inline diya_Result diya_Result_ok(void* ok_value) {
    return (diya_Result){
        .type = Ok,
        .value.ok = ok_value
    };
}

inline void* diya_Result_unwrap_error() {
    printf("[ERR] diya_result_unwrap: value is error\n");
    exit(1);
}

#define diya_Result_unwrap(type_, result) (result).type == Ok \
    ? (type_*) result.value.ok \
    : (type_*) diya_Result_unwrap_error()

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
} diya_LoggerLevel;

typedef struct {
    diya_String name;
    diya_LoggerLevel level;
} diya_Logger;


inline void diya_logger_warn(diya_Logger* logger, diya_String value) {
}

/// Logger

#endif
