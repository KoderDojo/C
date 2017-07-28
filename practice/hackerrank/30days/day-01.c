#include <stdio.h>
#include <string.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    // Declare second integer, double, and String variables.
    int j;
    double dbl;
    char str[50];

    // Read and save an integer, double, and String to your variables.
    scanf("%d", &j);
    scanf("%lf", &dbl);
    scanf(" %[^\n]", str);

    // Print the sum of both integer variables on a new line.
    printf("%d\n", i+j);

    // Print the sum of the double variables on a new line.
    printf("%.1lf\n", d+dbl);

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    char newStr[strlen(s) + strlen(str)];
    strcpy(newStr, s);
    strcat(newStr, str);
    printf("%s\n", newStr);

    return 0;
}