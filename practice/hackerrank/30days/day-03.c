#include <stdio.h>


int main(){
    int n;

    scanf("%d",&n);

    if (n % 2 == 1 || n >= 6 && n <= 20) {
        puts("Weird");
    } else {
        puts("Not Weird");
    }

    return 0;
}
