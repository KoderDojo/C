# Reduce and Functional Programming

I am mentoring a computer programming student in Python over the summer and a recent homework assignment in her course asked to count the number of vowels and consonants in a given string.

The student came up with this solution for vowels, and a similar solution for consonants.

```
def vowel_counter(s):
    vowels = ['a', 'e', 'i', 'o', 'u']
    total_vowels = 0

    for ch in s:
        if ch.lower() in vowels:
            total_vowels += 1

    return total_vowels


def main():
    name = input('Enter your name: ')
    print(vowel_counter(name))


main()
```

## Using Reduce

The student always challenges me to write solutions to the problems, and so I came up with a one-line solution using `lambda` as well as `reduce` in *functools*, because a one-liner is what the student is hoping for.

```
from functools import reduce


def main():
    name = input('Enter your name: ')
    print(reduce(lambda total, c: total+1 if c.lower() in ['a', 'e', 'i', 'o', 'u'] else total, name, 0))


main()
```

## Functional Programming in C

This got me thinking about **functional programming** in C, since I am learning C this summer. I wanted to use a `reduce` function like I did in Python to solve this problem.


```
#include <ctype.h>
#include <printf.h>

typedef int (*func)(char str);


int reduce(func f, char *str, int initialValue) {
    int results = initialValue;

    for(int i=0; str[i] != '\0'; i++) {
        results += f(str[i]);
    }

    return results;
}


int isVowel(char ch) {
    char chLower = tolower(ch);
    if (chLower < 'a' || chLower > 'z')
        return 0;

    return chLower == 'a' || chLower == 'e' || chLower == 'i'
            || chLower == 'o' || chLower == 'u';
}


int isConsonant(char ch) {
    char chLower = tolower(ch);
    if (chLower < 'a' || chLower > 'z')
        return 0;

    return chLower != 'a' && chLower != 'e' && chLower != 'i'
           && chLower != 'o' && chLower != 'u';
}


int main() {
    char name[30];

    fputs("Enter your name: ", stdout);
    scanf("%[^\n]", name);

    int totalVowels = reduce(isVowel, name, 0);
    int totalConsonants = reduce(isConsonant, name, 0);

    printf("Total Vowels: %d, Total Consonants: %d\n", totalVowels, totalConsonants);
}

```

Although not as succinct, the concept is the same. I created a `reduce` function that accepts a function, char array ( which is being used like an iterable in this case), and an initial value. It's very opinionated, which concerns me a bit, since C doesn't have *templates* or *generics*.

I saw the notion of *lambda functions* in C on stackoverflow, but haven't investigated it further. It's not a requirement for functional programming, but lambda functions are really useful for simple functions.

[What tools are there for functional programming in C?](https://stackoverflow.com/questions/216037/what-tools-are-there-for-functional-programming-in-c)

I'm looking forward to investigating this more in the future. The fact that I am even thinking about this stuff so early on in my learning of C makes me happy.