#include <assert.h>
#include <string.h>

char *words[] = {"I love you", "a little", "a lot", "passionately", "madly", "not at all"};

const char* how_much_i_love_you(int nb_petals) {
    return words[(nb_petals - 1) % 6];
}

int main() {
    assert(strcmp(how_much_i_love_you(7), "I love you") == 0);
    assert(strcmp(how_much_i_love_you(3), "a lot") == 0);
    assert(strcmp(how_much_i_love_you(6), "not at all") == 0);

    return 0;
}
