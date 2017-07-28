#include <assert.h>


int sumR (int *array, int n) {
    if (n == 0) return 0;

    return array[n-1] + sumR(array, n-1);
}


int main (int argc, char *argv[]) {
    assert(sumR (0, 0) == 0);
    assert(sumR ((int[]){1}, 1) == 1);
    assert(sumR ((int[]){1, 1, 1}, 3) == 3);
    return 0;
}
