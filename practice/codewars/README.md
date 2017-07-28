# Codewars

[Codewars](https://www.codewars.com/) is one of my favorite websites to practice programming challenges. Although it isn't necessary, I created a new account on Codewars just for C and C++ katas. I set my clan name as *DevNano* if you want to become allies at learning C and C++.

```
Username: devnano
Clan Name: DevNano
``` 

## Rank - C Language

One starts at 8 kyu on Codewars and as you do more and more programming challenges of increasing difficulty you increase that ranking. The highest I rank in Codewars is 4 kyu using Python. Here is my timeline for the C programming language.

* **8 kyu** - July 6, 2017
* **7 kyu** - July 14, 2017
* **6 kyu** - July 21, 2017
* **Focusing on Golang starting July 22, 2017**

![Codewars](../../assets/images/codewars-rank-c.png?raw=true)

## Testing

If you look at my code samples, you'll see I'm often using the **assert** macro in **<assert.h>** for simple testing. Here is an example of using assert in my very first kata using C.

```
#include <assert.h>
#include <string.h>

char *words[] = {"I love you", "a little", "a lot", "passionately", "madly", "not at all"};

const char* how_much_i_love_you(int nb_petals) {
    return words[(nb_petals - 1) % 6];
}

int main() {
    assert(strcmp(how_much_i_love_you(7), "I love you") == 0);
    assert(strcmp(how_much_i_love_you(3), "a lot") == 0);
    assert(strcmp(how_much_i_love_you(6), "not at all") == 0);

    return 0;
}
```

The code I submit to Codewars does not include the infrastructure to help me test, which in this case, is most of the code. Here is the code I sent to Codewars.

```
char *words[] = {"I love you", "a little", "a lot", "passionately", "madly", "not at all"};

const char* how_much_i_love_you(int nb_petals) {
    return words[(nb_petals - 1) % 6];
}
```



