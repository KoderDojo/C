#include <assert.h>
#include <string.h>


int is_string_palindrome(char* str) {
    for (int i = 0, j=strlen(str) -1; i < j; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }

    return 1;
}

int main() {

    assert(is_string_palindrome("") == 1);
    assert(is_string_palindrome("a") == 1);
    assert(is_string_palindrome("MADAM") == 1);
    assert(is_string_palindrome("race car") == 0);
    return 0;
}
