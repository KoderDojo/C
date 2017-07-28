#include <assert.h>


float opposite(float num) {
    return -num;
}

int main() {
    assert(opposite(-1) == 1);
    assert(opposite(14) == -14);
    assert(opposite(-34) == 34);

    return 0;
}
