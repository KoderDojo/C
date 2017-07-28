#include <assert.h>
#include <stdio.h>


int lenR (int *array) {
    return array == NULL || *array == 0 ? 0 : 1 + lenR(array + 1);
}

int main() {
    assert(lenR(0) == 0);
    assert(lenR((int[]){0}) == 0);
    assert(lenR ((int[]){1, 2, 3, 0}) == 3);

    return 0;
}
