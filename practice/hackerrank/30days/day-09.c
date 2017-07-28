#include <stdio.h>

int factorial(int n) {
    if (n < 2)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int n;
    scanf("%i", &n);
    int result = factorial(n);
    printf("%d\n", result);
    return 0;
}
