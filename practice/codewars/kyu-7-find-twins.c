#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

bool elimination(const int *arr, size_t arr_size, int* result) {
    if (arr_size < 1) return false;

    // O(n^2) - sort would be O(n*log(n))
    for(size_t i=0;i < arr_size-1;i++) {
        for(size_t j=i+1;j < arr_size;j++) {
            if (arr[i] == arr[j]) {
                *result = arr[i];
                return true;
            }
        }
    }

    return false;
}

int main() {
    int arr1[] = {2, 5, 34, 1, 22, 1};
    int value1;
    assert(elimination(arr1, sizeof(arr1) / sizeof(int), &value1));
    assert(value1 == 1);

    int arr2[] = {2, 2, 34, 1, 22};
    int value2;
    assert(elimination(arr2, sizeof(arr2) / sizeof(int), &value2));
    assert(value2 == 2);

    int arr3[] = {2, 5, 34, 1, 22};
    int value3;
    assert(elimination(arr3, sizeof(arr3) / sizeof(int), &value3) == false);

    return 0;
}
