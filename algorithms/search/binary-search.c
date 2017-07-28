/* ***********************************************************************
 *
 *                           Binary Search
 *
 *  Binary search requires a sorted array and continually divides the
 *  search area in half as it looks for the target value.
 *
 *  Worst case is the value is not found in the sequence.
 *
 *  Runs in O(logn).
 *
 *  In this example, Insertion Sort is used to sort the array of integers
 *  before binary search searches for the target value.
 *
 * ******************************************************************** */


#include <assert.h>


void insertionSort(int *array, int array_size) {
    for (int i=1; i < array_size; i++) {
        int value = array[i];

        int j = i-1;
        while(j > -1 && value < array[j]) {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = value;
    }
}


int binarySearch(int *array, int arr_size, int value) {
    int lo = 0; int hi = arr_size - 1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;

        if (array[mid] == value)
            return mid;

        if (array[mid] < value) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return -1;
}


int main (int argc, char *argv[]) {
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int array_size = sizeof(array)/sizeof(array[0]);

    insertionSort(array, array_size);

    for(int i=0; i < array_size; i++) {
        assert(binarySearch(array, array_size, i) == i);
    }

    assert(binarySearch(array, array_size, array[0] - 1) == -1);
    assert(binarySearch(array, array_size, array[array_size - 1] + 1) == -1);

    return 0;
}
