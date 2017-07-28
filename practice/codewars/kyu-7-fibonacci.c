#include <assert.h>


// Classic naive recursive fibonacci
int fib(int n) {
    if (n < 2) return n;

    return fib(n - 1) + fib(n - 2);
}

int main() {
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    assert(fib(5) == 5);

    return 0;
}
