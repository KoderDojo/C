#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remove_bang(char* s) {
    size_t length = strlen(s);
    char *str = calloc(length + 2, sizeof(char));

    int j = 0;
    for(int i=0; i < length; i++) {
        if (s[i] == '!')
            continue;

        str[j] = s[i];
        j++;
    }

    if (str[j] != '!')
        str[j] = '!';

    return str;
}

int main() {
    assert(strcmp(remove_bang("Hi"), "Hi!") == 0);
    assert(strcmp(remove_bang("Hi!"), "Hi!") == 0);
    assert(strcmp(remove_bang("Hi!!!!"), "Hi!") == 0);
    assert(strcmp(remove_bang("!Hi"), "Hi!") == 0);
    assert(strcmp(remove_bang("!Hi!"), "Hi!") == 0);
    assert(strcmp(remove_bang("Hi Hi!!"), "Hi Hi!") == 0);
    assert(strcmp(remove_bang("Hi!\nHi"), "Hi\nHi!") == 0);
}
