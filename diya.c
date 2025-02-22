#include "diya.h"


diya_Result diya_Test_result(const bool error) {
    if (error) {
        return diya_Result_error(diya_String_new("error"));
    }
    return diya_Result_ok("test");
}

int main(void) {
    diya_Result test = diya_Test_result(false);
    diya_RawString* raw_test = diya_Result_unwrap(diya_RawString, test);

    return 0;
}
