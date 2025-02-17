#ifndef DIYAC_H
#define DIYAC_H


// String

/* example:
 * int main() {
 *     DiyaString str = NewString("Hello world!");
 * }
*/
typedef struct {
    //TODO: bool heap;
    size_t size;
    char* value;
} DiyaString;

#define NewString(string) { \
    .value = string,\
    .size = sizeof(string) - 1\
}

#endif
