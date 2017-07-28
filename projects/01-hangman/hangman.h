/*****************************************************
 *
 * Hangman Game, version 1.0, by David Hayden
 *
 * My first cut at developing a hangman game using C.
 * I've only been learning C for a few weeks during
 * the summer of 2017 while visiting Alpine/Lehi, Utah.
 * This is my first project, but there will be many
 * more.
 *
 * In this project, I have tried to
 *
 * 1. Implement C features I have learned thus far.
 * 2. Write quality, self-documenting code.
 * 3. Minimize magic strings and numbers.
 * 4. Write useful code comments
 *
 * I've tried to make the functions adhere to the
 * single-responsibility principle (SRP) as much as
 * possible as well as encapsulate the algorithms and
 * internal data structures so I can refactor them
 * without breaking the API.
 *
 * I'm very interested in expanding the plugable
 * move functions so that I can create new computer
 * personas with more intelligence and AI capabilities.
 *
 ****************************************************/


#ifndef HANGMAN_BOARD_H
#define HANGMAN_BOARD_H


#define QUIT '#' // The symbol used to quit game.
#define MAX_WORD_LENGTH 25 // Maximum length of secret word.
#define MAX_LETTERS 26 // 26 letters in English alphabet.


typedef enum { false, true } bool;
typedef enum { lost, won } result; // Returned by playHangman function.
typedef enum { bad, good } guess; // Returned by addGuess function.


/* The hangman board struct keeps track of all game data.
 *
 * incorrectGuesses - current # of incorrect guesses.
 * maxIncorrectGuesses - maximum # of incorrect guesses allowed.
 * guesses - char array tracking letters guessed.
 *         - each cell represents a letter, 0 = a, 1 = b, ..., 25 = z.
 *         - if the letter has been guessed, the cell contains a 1.
 *         - if the letter has not been guessed, the cell contains a 0.
 * secretWord - the secret word being guessed by the player.
 */
typedef struct {
    int incorrectGuesses;
    int maxIncorrectGuesses;
    int guesses[MAX_LETTERS];
    char secretWord[MAX_WORD_LENGTH];
}Board;


// Player move prototype.
// Currently there are 2 options: userMove and randomMove.
typedef char (*move)(Board board);


/// Initializes the board and variables.
///
/// Most importantly, each cell in guesses is set to 0 ( i.e.
/// letter has not been guessed ).
///
/// \param board A pointer to the hangman board.
/// \param secretWord The secret word to be guessed by player.
/// \param maxAttempts The max # of incorrect guesses allowed by player.
void initBoard(Board *board, char *secretWord, int maxIncorrectGuesses);


/// Displays a banner, including the game name and max # of incorrect
/// guesses allowed.
///
/// \param board The hangman board.
void displayWelcomeScreen(Board board);


/// Displays the board, which is just the secret word at this time.
/// Guessed letters of the word are displayed, while letters not
/// guessed are displayed as an '_'. For secret word 'hello':
///
/// Secret Word: h _ l l _
///
/// \param board The hangman board.
void displayBoard(Board board);


/// Provides the available letters that have not been guessed by player.
/// This is used by randomMove to randomly pick a letter.
///
/// \param availableLetters A char array to fill with available letters.
/// \param board The hangman board.
void getAvailableLetters(char availableLetters[MAX_LETTERS + 1], Board board);


/// Displays the available letters that have not been guessed by player.
///
/// Available Letters: a b c d e f g h i j k l m n o p q r s t u v w x y z
///
/// \param board The hangman board.
void displayAvailableLetters(Board board);


/// Returns true if the letter has not been guessed by the player,
/// otherwise false. This function expects the letter to be a valid
/// lowercase letter of the English alphabet, which is used to
/// calculate the index for the char array 'guesses'.
///
/// \param board The hangman board.
/// \param letter The letter chosen by the player.
/// \return true if letter has not been guessed before, otherwise false.
bool isAvailableLetter(Board board, char letter);


/// Once the player chooses a letter, this processes the guess.
/// The guesses array is updated to show the letter has been guessed.
/// If the guess is incorrect, the incorrectGuesses variable is incremented.
///
/// \param board The hangman board.
/// \param letter The letter guessed by the player.
/// \return good if the guess is a good guess, otherwise bad.
guess addGuess(Board *board, char letter);


/// Returns true if the player have successfully guessed the secret word,
/// otherwise false. This is used to break out of the infinite game loop
/// and display 'congratulations' in 'displayResults'.
///
/// \param board The hangman board.
/// \return true if the player guesses the secret word, otherwise false.
bool wordGuessed(Board board);


/// Returns true if the player has reached the maximum number of incorrect guesses.
/// This is also used to break out of the infinite game loop and display
/// 'you lost' in 'displayResults'.
///
/// \param board The hangman board.
/// \return true if player reached max # of incorrect guesses, otherwise false.
bool playerLost(Board board);


/// Once game has finished, this function displays the results based on whether
/// 'wordGuessed' returns true or false. If true, one sees a congratulations,
/// otherwise the player lost.
///
/// \param board The hangman board.
void displayResults(Board board);


/// This is the main game loop. It requires the secret word, max number of
/// incorrect guesses allowed by player, and the 'move' function to call to
/// retrieve the letter guessed by the player.
///
/// There are 3 ways to leave this game loop:
///
/// 1. Player quits using the key defined in the 'QUIT' macro.
/// 2. Player reaches maximum incorrect guesses as determined by 'playerLost' function.
/// 3. Player wins by guessing the word as determined by 'wordGuessed' function.
///
/// \param secretWord The secret word to be guessed by player.
/// \param maxIncorrectGuesses The max # of incorrect guesses allowed by player.
/// \param playerMove The move function to call to retrieve the players letter choice.
/// \return won if the player guessed the word, otherwise lost.
result playHangman(char *secretWord, int maxIncorrectGuesses, move playerMove);

#endif //HANGMAN_BOARD_H
