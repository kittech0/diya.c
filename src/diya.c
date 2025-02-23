//
// Created by kittech on 22.02.25.
//
#include "diya.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

diya_String diya_String_new(const diya_RawString str) {
    return (diya_String){.value = str, .length = strlen(str)};
}

diya_Result diya_Result_error(const diya_String err_message) {
    return (diya_Result){.type = diya_ResultType_error, .value.err = err_message};
}

diya_Result diya_Result_ok(void* ok_value) {
    return (diya_Result){.type = diya_ResultType_ok, .value.ok = ok_value};
}

void diya_Logger_warn(const diya_Logger* logger, const diya_String str, ...) {
    if (diya_LoggerLevel_warn <= logger->level) {
        printf("\033[0;93m[%s] WARN:  %.*s\n",
               logger->name,
               (int)str.length,
               str.value
        );
    }
}

void diya_Logger_error(const diya_Logger* logger, const diya_String str, ...) {
    if (diya_LoggerLevel_error <= logger->level) {
        fprintf(stderr,
                "\033[0;91m[%s] ERROR: %.*s\n",
                logger->name,
                (int)str.length,
                str.value
        );
    }
}

void* _diya_Result_unwrap_error(const diya_Logger* logger, const diya_String error_str) {
    diya_Logger_error(logger, error_str);
    exit(1);
}


