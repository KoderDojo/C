#include <assert.h>


int solution(int number) {
    int total = 0;

    for(int i=3; i<number; i = i+3) {
        total += i;
    }

    for(int i=5; i<number; i = i+5) {
        if (i % 3 != 0)
            total += i;
    }

    return total;
}


// Test Code
int main (int argc, char *argv[]) {
    assert(solution(10) == 23);

    return 0;
}
