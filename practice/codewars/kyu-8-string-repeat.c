#include <assert.h>
#include <stdlib.h>
#include <string.h>


char *repeat_str(size_t count, const char *src) {
    char *repeatedString = calloc(count * strlen(src) + 1, sizeof(char));

    while (count > 0) {
        strcat(repeatedString, src);
        count--;
    }

    return repeatedString;
}


char *repeat_str2(size_t count, const char *src) {
    size_t length = strlen(src);
    char *repeatedString = malloc(count * length + 1);

    int i = 0;
    while(count > 0) {
        strcpy(repeatedString + i, src);
        count --;
        i += length;
    }

    return repeatedString;
}


int main() {
    char *ret = repeat_str(3, "hello ");
    assert(strcmp(ret, "hello hello hello ") == 0);
    free(ret);

    ret = repeat_str2(3, "hello ");
    assert(strcmp(ret, "hello hello hello ") == 0);
    free(ret);
}
