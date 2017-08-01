#include <stdio.h>


void flip_vertical_axis(int n, int matrix[n][n]){
    if (n < 2) return;

    int j = n - 1;
    for (int i=0; i < j; i++) {
        for (int k=0; k < n; k++) {
            int temp = matrix[k][i];
            matrix[k][i] = matrix[k][j];
            matrix[k][j] = temp;
        }
        j--;
    }
}

void print_matrix(int n, int matrix[n][n]) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

int main() {
    int matrix[2][2] = {1, 0, 1, 0};
    flip_vertical_axis(2, matrix);
    print_matrix(2, matrix);
    return 0;
}
