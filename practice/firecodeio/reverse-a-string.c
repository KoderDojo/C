#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
char* reverse_string (char* str){
    char* output_string = NULL;
    /* Calculate length of the string */
    size_t len = strlen(str);
    /* allocate memory of size equal to the length of the given string */
    output_string = (char *)calloc((len+1), (sizeof(char)));
    // Add your code below this line. Do not modify any other code

    for(size_t i=len-1, j=0; i > -1; i--, j++) {
        output_string[j] = str[i];
    }

    // Add your code above this line. Do not modify any other code
    return output_string;
}
