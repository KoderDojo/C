#include <assert.h>


int reverse(int num) {
    int revnum = 0;
    int neg = 0;

    if (num < 0) {
        num = -num;
        neg = 1;
    }

    while(num) {
        revnum = revnum * 10 + (num % 10);
        num = num / 10;
    }

    if (neg) { revnum = -revnum; }

    return revnum;
}

int main() {
    assert(reverse(123) == 321);
    assert(reverse(-15) == -51);
    
    return 0;
}
