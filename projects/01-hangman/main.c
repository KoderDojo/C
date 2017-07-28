#include "hangman.h"
#include "moves.h"


int main() {
    char secretWord[MAX_WORD_LENGTH] = "hello";
    int maxIncorrectGuesses = 5;
    move playerMove = userMove;

    // The hangman game expects the secret word,
    // the maximum number of incorrect guesses,
    // and the player move function.
    playHangman(secretWord, maxIncorrectGuesses, playerMove);
}
