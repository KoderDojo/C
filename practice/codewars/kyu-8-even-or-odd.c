#include <assert.h>
#include <string.h>

const char * even_or_odd(int number) {
    return number % 2 == 0 ? "Even" : "Odd";
}

int main() {
    assert(strcmp(even_or_odd(2), "Even") == 0);
    assert(strcmp(even_or_odd(1), "Odd") == 0);
    assert(strcmp(even_or_odd(6), "Even") == 0);
    assert(strcmp(even_or_odd(21), "Odd") == 0);
    assert(strcmp(even_or_odd(100), "Even") == 0);
}