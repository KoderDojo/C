#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i < n; i++) {
        char s[10000];
        scanf("%s", s);

        int length = strlen(s);

        // Even characters
        for (int j = 0; j < length; j = j + 2) {
            printf("%c", s[j]);
        }

        fputs(" ", stdout);

        // Odd characters
        for (int j = 1; j < length; j = j + 2) {
            printf("%c", s[j]);
        }

        puts("");
    }

    return 0;
}
