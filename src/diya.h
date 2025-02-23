#ifndef DIYAC_H
#define DIYAC_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__CYGWIN__)
#define SYSTEM "windows"
#elif defined(__unix__)
#define SYSTEM "unix"
#elif defined(__APPLE__)
#define SYSTEM "macos"
#elif
#define SYSTEM "none"
#endif

/// String

typedef char* diya_RawString;

typedef struct {
    size_t length;
    diya_RawString value;
} diya_String;

diya_String diya_String_new(diya_RawString str);
#define STR(str) diya_String_new(str)
bool diya_String_equal(diya_String str1, diya_String str2);

/// String


///TODO: Arena allocator


///TODO: Arena allocator

/// Logger TODO
typedef enum {
    diya_LoggerLevel_silent,
    diya_LoggerLevel_error,
    diya_LoggerLevel_warn,
    diya_LoggerLevel_log,
    diya_LoggerLevel_info,
    diya_LoggerLevel_debug,
} diya_LoggerLevel;

typedef struct {
    const diya_RawString name;
    const diya_LoggerLevel level;
} diya_Logger;

void diya_Logger_warn(const diya_Logger* logger, const diya_String str, ...);
void diya_Logger_error(const diya_Logger* logger, const diya_String str, ...);


/// Logger

/// Result

typedef enum {
    diya_ResultType_error,
    diya_ResultType_ok
} diya_ResultType;

typedef struct {
    diya_ResultType type;

    union {
        const diya_String err;
        void* ok;
    } value;
} diya_Result;

diya_Result diya_Result_error(diya_String err_message);
diya_Result diya_Result_ok(void* ok_value);
void* _diya_Result_unwrap_error(const diya_Logger* logger, const diya_String error_str);

#define UNWRAP(type_,result) ((result).type == diya_ResultType_ok \
? (type_*) result.value.ok \
: (type_*) _diya_Result_unwrap_error(&_logger,result.value.err))

/// Result

/// Util

/// Util
#endif
