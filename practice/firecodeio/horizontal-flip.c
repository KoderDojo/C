#include <assert.h>


void flip_horizontal_axis(int n, int matrix[n][n]){
    if (n < 2) return;

    int lo = 0, hi = n - 1;

    while (lo < hi) {
        for(int i=0; i < n; i++) {
            int temp = matrix[lo][i];
            matrix[lo][i] = matrix[hi][i];
            matrix[hi][i] = temp;
        }

        lo++, hi--;
    }
}

int main() {
    int matrix[3][3] = { {1, 1, 1}, {1, 0, 0}, {1, 0, 1} };
    int expected[3][3] = { {1, 0, 1}, {1, 0, 0}, {1, 1, 1} };
    flip_horizontal_axis(3, matrix);

    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            assert(matrix[i][j] == expected[i][j]);
        }
    }

    return 0;
}
