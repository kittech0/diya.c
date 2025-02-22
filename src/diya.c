//
// Created by kittech on 22.02.25.
//
#include "diya.h"

#include <stdio.h>
#include <stdlib.h>

diya_String diya_String_new(const diya_RawString str) {
    return (diya_String){.value = str, .length = sizeof(str) - 1};
}

diya_Result diya_Result_error(const diya_String err_message) {
    return (diya_Result){.type = Error, .value.err = err_message};
}

diya_Result diya_Result_ok(void* ok_value) {
    return (diya_Result){.type = Ok, .value.ok = ok_value};
}

void diya_Logger_warn(const diya_Logger* logger, const diya_String str, ...) {
    if (warn <= logger->level) {
        printf("[%s] WARN:  %.*s\n", logger->name, str.length, str.value);
    }
}

void diya_Logger_error(const diya_Logger* logger, const diya_String str, ...) {
    if (error <= logger->level) {
        fprintf(stderr, "[%s] ERROR: %.*s\n", logger->name, str.length, str.value);
    }
}

void* _diya_Result_unwrap_error(const diya_Logger* logger, const diya_String error_str) {
    diya_Logger_error(logger, error_str);
    exit(1);
}


