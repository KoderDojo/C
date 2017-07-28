/* ***********************************************************************
 *
 *                           Insertion Sort
 *
 *  Insertion sort is a popular sorting algorithm for smaller-sized arrays.
 *  Many sophisticated sorting algorithms will drop down to using insertion
 *  sort for sorting smaller list of values.
 *
 *  Insertion sort iterates through the array one at a time, making sure
 *  the left side of the array is sorted as it progresses from left-to-
 *  right. It plucks the next value from the array and shifts the left-side
 *  of the array as necessary to put that value in its sorted position.
 *
 *  Runs in O(n^2).
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


int main (int argc, char *argv[]) {
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int array_size = sizeof(array)/sizeof(array[0]);

    insertionSort(array, array_size);

    for(int i=0; i < array_size; i++) {
        assert(array[i] == i);
    }

    return 0;
}
