#include <stdio.h>

#include "diya.h"

static const diya_Logger _logger = (diya_Logger){
    .level = diya_LoggerLevel_warn,
    .name = "diya.test"
};
/// TODO: make automatic logger (testing rn)
// #define LOGGER(name) static const diya_Logger _logger = (diya_Logger){\
// .level = warn,\
// .name = name\
// };
//
// LOGGER(diya_String_new("diya.test"));

diya_Result diya_Test_result(const bool error) {
    return error
               ? diya_Result_error(STR("error"))
               : diya_Result_ok("test");
}

void test(void) {
    printf("test: %d", __linux__);
}

int main(void) {
    /// TODO: gotta make it work
    diya_Logger_warn(&_logger, STR("test"));
    diya_Logger_warn(&_logger, STR("test"));
    diya_Logger_warn(&_logger, STR("test"));
    const diya_Result test = diya_Test_result(false);
    diya_RawString* raw_test = UNWRAP(diya_RawString, test);
    char skibid[129] = {-1, 'a', -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -100, -128, '\n'};
    printf("%s", skibid);
}
