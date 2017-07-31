#include <assert.h>
#include <string.h>


/*
 * Could use a HashTable for O(n).
 * If I had a good sort, O(nlogn).
 * This is O(n^2).
 */
int are_all_characters_unique(char* str){
    if (str == NULL) return 0;

    size_t length = strlen(str);
    if (length < 2) return 1;

    for(int i = 0; i < length - 1; i++) {
        int j=i + 1;
        while (j < length) {
            if (str[i] == str[j])
                return 0;
            j++;
        }
    }

    return 1;
}

int main() {
    assert(are_all_characters_unique("123!@") == 1);
    assert(are_all_characters_unique("") == 1);
    assert(are_all_characters_unique("A") == 1);
    assert(are_all_characters_unique("Not unique") == 0);
    assert(are_all_characters_unique(NULL) == 0);

    return 0;
}
