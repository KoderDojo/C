#include <assert.h>
#include <stdlib.h>


typedef struct {
    int original;
    int weighted;
}Value;


Value *createArrayOfValues(int *array, int arrayLength) {
    Value *newArray = (Value *)malloc(arrayLength * sizeof(Value));

    for(int i=0; i < arrayLength; i++) {
        newArray[i].original = array[i];
        newArray[i].weighted = array[i] * (i+1);
    }

    return newArray;
}


// Selection Sort: O(n^2)
void sort(Value *array, int arrayLength) {
    for(int i=0; i < arrayLength-1; i++) {
        int minValue = array[i].weighted;
        int minIndex = i;

        for(int j=i+1; j < arrayLength; j++) {
            if (array[j].weighted < minValue) {
                minValue = array[j].weighted;
                minIndex = j;
            }
        }

        Value temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}


int* sortByValueAndIndex(int* array, int arrayLength) {
    Value *valuesArray = createArrayOfValues(array, arrayLength);
    sort(valuesArray, arrayLength);

    int *sortedArray = malloc(arrayLength * sizeof(int));
    for (int i=0; i < arrayLength; i++) {
        sortedArray[i] = valuesArray[i].original;
    }

    return sortedArray;
}


// Test Helper Forward Declaration
int cmp(int *array1, int *array2, size_t n);


int main (int argc, char *argv[]) {
    int array1[] = { 1, 2, 3, 4, 5 };
    int expected1[] = { 1, 2, 3, 4, 5 };
    int* actual1 = sortByValueAndIndex(array1, 5);
    assert(cmp(actual1, expected1, 5));

    int array2[] = { 23, 2, 3, 4, 5 };
    int expected2[] = { 2, 3, 4, 23, 5 };
    int* actual2 = sortByValueAndIndex(array2, 5);
    assert(cmp(actual2, expected2, 5));

    int array3[] = { 26, 2, 3, 4, 5 };
    int expected3[] = { 2, 3, 4, 5, 26 };
    int* actual3 = sortByValueAndIndex(array3, 5);
    assert(cmp(actual3, expected3, 5));

    int array4[] = { 9, 5, 1, 4, 3 };
    int expected4[] = { 1, 9, 5, 3, 4 };
    int* actual4 = sortByValueAndIndex(array4, 5);
    assert(cmp(actual4, expected4, 5));
}


int cmp(int *array1, int *array2, size_t n) {
    for (int i=0; i < n; i++) {
        if (array1[i] != array2[i]) {
            return 0;
        }
    }

    return 1;
}
