#include <assert.h>
#include <math.h>


int index (int *array, int size, int n) {
    if (n >= size) return -1;
    return pow(array[n],n);
}

int main() {
    assert(index (0, 0, 0) == -1);
    assert(index ((int []){1, 2, 3, 4}, 4, 2) == 9);
    assert(index ((int []){1, 3, 10, 100}, 4, 3) == 1000000);
}
