#include <assert.h>
#include <stdlib.h>

// Test Helper Forward Declaration
int cmp(int *array1, int *array2, size_t n);

int *replaceAll (int *array, int n, int old, int new) {
    int *newArray = (int *)malloc(n * sizeof(int));

    for(int i=0; i < n; i++) {
        newArray[i] = array[i] == old ? new : array[i];
    }

    return newArray;
}


int main (int argc, char *argv[]) {
    assert(cmp(replaceAll((int[]){}, 0, 1, 2), (int[]){}, 0));
    assert(cmp(replaceAll((int[]){1}, 1, 1, 2), (int[]){2}, 1));
    assert(cmp(replaceAll((int[]){1, 2, 2}, 3, 1, 2), (int[]){2, 2, 2}, 3));
}


int cmp(int *array1, int *array2, size_t n) {
    for (int i=0; i < n; i++) {
        if (array1[i] != array2[i]) {
            return 0;
        }
    }

    return 1;
}
