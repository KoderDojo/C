#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "hangman.h"


char userMove(Board board) {
    char letter;

    while(true) {
        printf("Choose a letter or '%c' to quit: ", QUIT);
        scanf(" %c", &letter);
        puts("");

        if (letter == QUIT)
            break;

        // Must be alphabetical
        if (!isalpha(letter) ) {
            printf("'%c' is an invalid choice.\n\n", letter);
            continue;
        }

        // Must be lowercase
        letter = (char)tolower(letter);

        if (isAvailableLetter(board, letter))
            break;

        printf("'%c' has already been chosen. Try again.\n\n", letter);
    }

    return letter;
}


char randomMove(Board board) {
    char availableLetters[MAX_LETTERS + 1];

    // Get letters that have not been chosen.
    getAvailableLetters(availableLetters, board);

    // Pick a random letter
    int maxRange = (int)strlen(availableLetters) - 1;
    srand(time(NULL));
    int r = rand() % maxRange;

    return availableLetters[r];
}
