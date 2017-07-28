#include <assert.h>
#include <stdio.h>

int getAge(const char *inputString) {
    int age;
    sscanf(inputString, "%d", &age);
    return age;
}

int main() {
    assert(getAge("5 years old") == 5);
    assert(getAge("9 years old") == 9);
    assert(getAge("1 years old") == 1);
}
