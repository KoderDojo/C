#include <assert.h>
#include <stdlib.h>


int sumArray(const int *values, int length) {
    int total = 0;

    for(int i=0; i < length; i++) {
        total += values[i];
    }

    return total;
}


int find_even_index(const int *values, int length) {
    if (length == 0) return 0;

    int leftTotal = 0;
    int rightTotal = sumArray(values, length) - values[0];

    int i;
    for(i=0; i < length; i++) {
        if (leftTotal == rightTotal)
            return i;

        leftTotal += values[i];
        rightTotal -= values[i+1];
    }

    return -1;
}


// Test Code
int main (int argc, char *argv[]) {
    {
        int arr[] = {1, 2, 3, 4, 3, 2, 1};
        int expected = 3;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { 1,100,50,-51,1,1 };
        int expected = 1;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { 20,10,-80,10,10,15,35 };
        int expected = 0;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { -1,-2,-3,-4,-3,-2,-1 };
        int expected = 3;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    return 0;
}
