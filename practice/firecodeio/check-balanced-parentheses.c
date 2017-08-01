#include <assert.h>
#include <string.h>


int balanced(const char *str) {
    size_t length = strlen(str);

    if (length % 2 == 1) return 0;

    int index = -1;
    for(int i=0; i < length; i++) {
        if (str[i] == '(') {
            index += 1;
            continue;
        }

        if (index < 0 || str[index] != '(')
            return 0;

        index--;
    }

    return 1;
}

int main() {
    assert(balanced("()()()") == 1);
    assert(balanced("(())") == 1);
    assert(balanced("(()") == 0);
    assert(balanced("(())()") == 1);
    assert(balanced("(") == 0);
    assert(balanced("())(") == 0);
    return 0;
}
