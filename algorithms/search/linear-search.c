/* ***********************************************************************
 *
 *                           Linear Search
 *
 *  A linear search is a sequential search that searches for a value
 *  in a sequence by checking each value one at a time until the value
 *  is found or all items have been checked.
 *
 *  Worst case is the value is not found in the sequence.
 *
 *  Runs in O(n).
 *
 *  Note: The values in the array are purposely populated in numerical
 *  order by index for 2 reasons. One, it makes it easy to verify
 *  linear search is operating properly. Two, similar code will be
 *  used for binary search.
 *
 * ******************************************************************** */


#include <stdio.h>

#define SIZE 100

typedef enum {false = 0, true = 1}bool;


// Forward declarations.
void fillArray(int *array);
int chooseValueToFind();
int findUsingLinearSearch(int *array, int value);


int main() {
    int array[SIZE];

    // Fill the array with a list of integers
    // from 0 to SIZE - 1.
    fillArray(array);

    // Ask the user for an integer to find
    // in the array.
    int valueToFind = chooseValueToFind();

    // Search the array for the user chosen
    // integer. If found, returns the index
    // location, otherwise returns -1
    int index = findUsingLinearSearch(array, valueToFind);

    if (index == -1)
        printf("The value was not found in the array.");
    else
        printf("The value %d is located in the array at index %d.", valueToFind, index);
}


/// Performs a linear search of the array to find the value.
///
/// \param array The array to search.
/// \param value The value to find in the array.
/// \return array index if the value is found, otherwise -1.
int findUsingLinearSearch(int *array, int value) {
    bool found = false;
    int index = -1;

    while(index < SIZE && !found) {
        index++;

        if (array[index] == value)
            found = true;
    }

    return index < SIZE ? index : -1;
}


/// Asks the user to enter a value to find in the array.
///
/// \return The value to find in the array.
int chooseValueToFind() {
    int chosenValue;

    printf("Enter integer value to find in array: ");
    scanf("%d", &chosenValue);

    return chosenValue;
}


/// Fills the array with a list of integers.
/// For simplicity, the value stored in each
/// index position is the index.
///
/// \param array The array to fill with integers.
void fillArray(int *array) {
    for(int i=0; i < SIZE; i++) {
        array[i] = i;
    }
}
