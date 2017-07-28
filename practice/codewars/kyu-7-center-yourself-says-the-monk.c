#include <assert.h>
#include <stdlib.h>
#include <string.h>


char *center(const char *strng, int width, char fill) {
    size_t strngLength = strlen(strng);

    if (strngLength >= width) return strdup(strng);

    char *centeredString = (char *)calloc(width + 1, sizeof(char));

    // Fill string with padding character
    for(int i=0; i < width; i++) {
        centeredString[i] = fill;
    }

    // Center string
    int amountOfPadding = width - strngLength;
    int strngLeft = amountOfPadding / 2 + amountOfPadding % 2;
    memcpy(centeredString+strngLeft, strng, strngLength);

    return centeredString;
}


int main (int argc, char *argv[]) {
    assert(strcmp(center("a", 3, ' '), " a ") == 0);
    assert(strcmp(center("____abc___", 10, '_'), "____abc___") == 0);
    assert(strcmp(center("abcdefg", 2, ' '), "abcdefg") == 0);
    return 0;
}
