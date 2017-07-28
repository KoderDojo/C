#include "hangman.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void initBoard(Board *board, char secretWord[], int maxIncorrectGuesses) {
    board->incorrectGuesses = 0;
    board->maxIncorrectGuesses = maxIncorrectGuesses;

    strcpy(board->secretWord, secretWord);

    // Keeping track of letters guessed.
    // 0 is for 'a', 1 is for 'b', ..., 25 is for 'z'.
    // if guesses[i] == 0, the letter has not been guessed.
    // if guesses[i] == 1, the letter has been guessed.
    // Initializing all cells to 0 ( not guessed ) at
    // beginning of game.
    for(int i=0; i < MAX_LETTERS; i++)
        board->guesses[i] = 0;
}


void displayWelcomeScreen(Board board) {
    puts("\n\n****************** Hangman ********************");
    puts("*                                             *");
    puts("* Guess the secret word by choosing letters   *");
    puts("* 'a' through 'z'. You can quit at any time   *");
    printf("* using the '%c' symbol.                       *\n", (char)QUIT);
    puts("*                                             *");
    printf("* You get %d incorrect guesses.                *\n", board.maxIncorrectGuesses);
    puts("*                                             *");
    puts("***********************************************");
    puts("\nLet's Begin!");
}


void displayBoard(Board board) {
    fputs("\n\n\nSecret Word: ", stdout);

    for(int i=0; board.secretWord[i] != '\0'; i++) {
        char letter = board.secretWord[i];

        // if letter guessed, display it.
        // Otherwise, display '_'
        if (board.guesses[letter - 'a'])
            printf("%c ", letter);
        else
            fputs("_ ", stdout);
    }

    puts("");
}


void getAvailableLetters(char availableLetters[MAX_LETTERS + 1], Board board) {
    int i = 0, j = 0;

    for(i=0; i < MAX_LETTERS + 1; i++) {
        if (!board.guesses[i]) {
            availableLetters[j] = (char) (i + 'a');
            j++;
        }
    }

    availableLetters[j] = '\0';
}


void displayAvailableLetters(Board board) {
    fputs("\nAvailable Letters: ", stdout);

    // Display all letters that have not been guessed.
    // This would be where guesses[i] == 0.
    for(int i=0; i < MAX_LETTERS; i++) {
        if (!board.guesses[i])
            printf("%c ", (char)(i + 'a'));
    }

    puts("\n");
}


bool isAvailableLetter(Board board, char letter) {
    return board.guesses[letter - 'a'] == 0 ? true : false;
}


// TODO: Add a 3rd guess option as invalid instead of exiting.
guess addGuess(Board *board, char letter) {
    // All letters at this point should be
    // available and accurate because the
    // 'move' function should verify input.
    // Exit if the letter is not between
    // 'a' - 'z' or not available.
    if (letter < 'a' || letter > 'z') {
        printf("Invalid letter: %c.", letter);
        exit(1);
    }

    if (board->guesses[letter-'a'] == 1) {
        puts("Letter already guessed.");
        exit(1);
    }

    // Mark the letter as guessed.
    board->guesses[letter - 'a'] = 1;

    // Determine if this is a good or bad guess.
    // Assume bad and only make good if the letter
    // is in the secret word.
    guess playerGuess = bad;
    for(int i=0; board->secretWord[i] != '\0'; i++) {
        if (board->secretWord[i] == letter) {
            playerGuess = good;
            break;
        }
    }

    if (playerGuess == bad)
        board->incorrectGuesses++;

    return playerGuess;
}


bool wordGuessed(Board board) {
    for(int i=0; board.secretWord[i] != '\0'; i++) {
        if (board.guesses[board.secretWord[i] - 'a'] == 0) {
            return false;
        }
    }

    return true;
}


bool playerLost(Board board) {
    return board.incorrectGuesses == board.maxIncorrectGuesses ? true : false;
}


void displayResults(Board board) {
    puts("\n\n****************** Results ********************");

    if (wordGuessed(board)) {
        puts("\nCongratulations you won!");
    } else {
        puts("\nYou Lost.");
    }

    printf("\nThe secret word was '%s'.\n", board.secretWord);
    puts("\nThank you for playing!");
}


result playHangman(char *secretWord, int maxInvalidAttempts, move playerMove) {
    Board board;

    initBoard(&board, secretWord, maxInvalidAttempts);

    displayWelcomeScreen(board);

    // Continue playing until word guessed or player loses or quits.
    while(1) {
        displayBoard(board);

        displayAvailableLetters(board);

        char letterChosen = playerMove(board);
        if(letterChosen == QUIT)
            break;

        guess playerGuess = addGuess(&board, letterChosen);
        if (playerGuess == bad) {
            printf("---> '%c' is not in the word. You have %d incorrect guesses left.\n",
                   letterChosen, board.maxIncorrectGuesses - board.incorrectGuesses);
        } else {
            printf("---> Yes! '%c' is in the word!\n", letterChosen);
        }

        if (wordGuessed(board) || playerLost(board))
            break;
    }

    displayResults(board);

    return wordGuessed(board) ? won : lost;
}
