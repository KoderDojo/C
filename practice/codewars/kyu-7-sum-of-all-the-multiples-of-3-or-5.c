#include <assert.h>


int findSum (int n) {
    int total = 0;

    for(int i=3; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            total += i;
    }

    return total;
}


int main (int argc, char *argv[]) {
    assert(findSum (5) == 8);
    assert(findSum (10) == 33);
    assert (findSum (100) == 2418);
    assert (findSum (1000) == 234168);
}
