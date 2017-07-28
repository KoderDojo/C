#include <printf.h>


int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}


int main() {
    int n;
    int streak = 0, maxStreak = 0;

    scanf("%d", &n);

    while(1) {
        if (n % 2 == 1) {
            streak++;
            maxStreak = max(maxStreak, streak);
        }
        else
            streak = 0;

        if (n < 2)
            break;

        n /= 2;
    }

    printf("%d", maxStreak);
}
