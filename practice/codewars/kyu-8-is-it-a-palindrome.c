#include <assert.h>
#include <ctype.h>
#include <string.h>

int isPalindrom (const char *s) {
    int length = strlen(s);

    int j=0;
    for (int i=length-1; i >=0; i--) {
        if (j >= i)
            return 1;

        if(tolower(s[i]) != tolower(s[j]))
            return 0;

        j++;
    }
}


int main() {
    assert(isPalindrom("a") == 1);
    assert(isPalindrom ("aba") == 1);
    assert(isPalindrom ("Abba") == 1);
    assert(isPalindrom ("hello") == 0);
    return 0;
}
