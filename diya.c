#include "diya.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// String

diya_str_t diya_str_new(diya_str_raw_t* str) {
    const size_t length = sizeof(str) - 1;
    const diya_str_t diya_str = {
        .value = str,
        .length = length
    };
    return diya_str;
}

bool diya_str_equal(const diya_str_t str1, const diya_str_t str2) {
    if (str1.length != str2.length) return false;
    for (int i = 0; i < str1.length; i++) {
        if (str1.value[i] != str2.value[i]) return false;
    }
    return true;
}

/// String

/// Result

diya_result_t diya_result_error(diya_str_t err_message) {
    return (diya_result_t){
        .type = err,
        .value.err = err_message
    };
}

diya_result_t diya_result_ok(void* ok_value) {
    return (diya_result_t){
        .type = ok,
        .value.ok = ok_value
    };
}

/// Result


int main(void) {
    diya_logger_t logger = {
        .name = diya_str_new("test"),
        .level = debug
    };
    diya_str_t value = diya_str_new("test");
    const diya_result_t result = diya_result_ok(&value);
    diya_str_t* test;
    diya_result_unwrap(diya_str_t, test, result);

    return 0;
}
