/* ***********************************************************************
 *
 *                           Selection Sort
 *
 *  Selection sort finds the k'th smallest value in the array after each
 *  pass and puts it in the k'th position in the array. It's not as
 *  popular as Insertion sort, but has the same worse case runtime. In
 *  practice, it is not as fast as Insertion sort.
 *
 *  Runs in O(n^2).
 *
 * ******************************************************************** */


#include <assert.h>


void selectionSort(int *array, int arrayLength) {
    for(int i=0; i < arrayLength-1; i++) {
        int minValue = array[i];
        int minIndex = i;

        for(int j=i+1; j < arrayLength; j++) {
            if (array[j] < minValue) {
                minValue = array[j];
                minIndex = j;
            }
        }

        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}


int main (int argc, char *argv[]) {
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int array_size = sizeof(array)/sizeof(array[0]);

    selectionSort(array, array_size);

    for(int i=0; i < array_size; i++) {
        assert(array[i] == i);
    }

    return 0;
}
