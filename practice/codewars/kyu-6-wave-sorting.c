/*
 * Most coders answered this using built-in qsort,
 * which feels like cheating.
 *
 * This is certainly not an ideal solution and I
 * could rewrite this using a bit of functional
 * programming. Create a reduce function and pass
 * in comparison functions.
 *
 */


#include <assert.h>


int findMaxIndex(int *arr, int startIndex, int arr_size) {
    int maxIndex = startIndex;
    int maxValue = arr[maxIndex];

    for(int i=startIndex+1; i < arr_size; i++) {
        if (arr[i] > maxValue) {
            maxIndex = i;
            maxValue = arr[i];
        }
    }

    return maxIndex;
}


int findMinIndex(int *arr, int startIndex, int arr_size) {
    int minIndex = startIndex;
    int minValue = arr[minIndex];

    for(int i=startIndex+1; i < arr_size; i++) {
        if (arr[i] < minValue) {
            minIndex = i;
            minValue = arr[i];
        }
    }

    return minIndex;
}


void wave_sort(int arr[], int arr_size){
    if (arr_size < 2) return;

    for(int i=0; i < arr_size; i++) {
        int index = i % 2 == 0 ? findMaxIndex(arr, i, arr_size) : findMinIndex(arr, i, arr_size);

        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;

        // Solve problem when 2 identical
        // numbers side-by-side. Has to hold
        // true for the array to be wave-sortable.
        if (i > 0 && arr[i] == arr[i-1]) {
            temp = arr[i];
            arr[i] = arr[i-4];
            arr[i-4] = temp;
        }
    }
}


// Forward Declare Test Helper
void cmpIntArrays(int *arr, int *arr2, int arr_size);


// Test Code
int main (int argc, char *argv[]) {
    int arr[] = {9, 47, 22, 23, 33, 14, 46, 9, 29, 39, 13, 29, 44, 91};
    int expected[] = { 91, 9, 47, 9, 46, 13, 44, 14, 39, 29, 33, 23, 29, 22};
    int n = sizeof arr / sizeof *arr;
    wave_sort(arr, n);
    cmpIntArrays(arr, expected, n);

    return 0;
}


void cmpIntArrays(int *arr, int *arr2, int arr_size) {
    for(int i=0; i < arr_size; i++) {
        assert(arr[i] == arr2[i]);
    }
}
