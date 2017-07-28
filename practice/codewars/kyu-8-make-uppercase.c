#include <assert.h>
#include <ctype.h>
#include <string.h>

char *makeUpperCase (char *string) {
    char *uppercaseString = strdup(string);

    for(int i=0; uppercaseString[i] != '\0'; i++) {
        uppercaseString[i] = toupper(uppercaseString[i]);
    }

    return uppercaseString;
}

int main() {
    assert(strcmp(makeUpperCase("HelLo"), "HELLO") == 0);
    assert(strcmp(makeUpperCase("hello world"), "HELLO WORLD") == 0);
    assert(strcmp(makeUpperCase("HELLO"), "HELLO") == 0);
}
