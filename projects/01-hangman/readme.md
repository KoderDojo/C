# Hangman

My first personal project while learning C is a **hangman game**. At the time of its creation, I've been learning C for about 2 to 3 weeks while visiting the Salt Lake City area during the summer of 2017.

Although it is a simple game, I've tried to write high quality C code to the best of my ability. I've focused on the following:

* Functions that are focused and adhere to the **Single-Responsibility Principle** as much as possible.
* **Encapsulation** of algorithms and internal data structures such that future refactorings should minimize breaking the API.
* **Self-documenting code** by using well-named variables, functions, enums and other user defined types to clarify intent.
* **Code comments** to help myself and other developers understand and maintain the code.
* **Macros** to eliminate magic strings and numbers.
* Use of **header and source files** to distinguish the API/interface from implementation.

## Game

The hangman game is a console game using *stdin* and *stdout* in C. The game starts with a call to **playHangman**, which accepts 3 parameters.

```
playHangman(secretWord, maxIncorrectGuesses, playerMove)

```
* **secretWord** - the word to be guessed by the player.
* **maxIncorrectGuesses** - maximum number of incorrect guesses allowed by the player.
* **playerMove** - a pluggable move function that returns a guess.

Once **playHangman** is called the welcome screen, hangman board, and available letters are displayed on the screen and **playerMove** is invoked to retrieve an appropriate guess.

The game responds appropriately to player guesses and continues playing until the player either 1) guesses the secret word, 2) quits, or 3) reaches the maximum number of incorrect guesses.

```
****************** Hangman ********************
*                                             *
* Guess the secret word by choosing letters   *
* 'a' through 'z'. You can quit at any time   *
* using the '#' symbol.                       *
*                                             *
* You get 5 incorrect guesses.                *
*                                             *
***********************************************

Let's Begin!



Secret Word: _ _ _ _ _ 

Available Letters: a b c d e f g h i j k l m n o p q r s t u v w x y z 

Choose a letter or '#' to quit: h

---> Yes! 'h' is in the word!



Secret Word: h _ _ _ _ 

Available Letters: a b c d e f g i j k l m n o p q r s t u v w x y z 

Choose a letter or '#' to quit:
```

When the game is finished, a simple *you won* or *you lost* message is displayed along with the secret word.

```
****************** Results ********************

Congratulations you won!

The secret word was 'hello'.

Thank you for playing!
```
## Player Moves

The **moves** header and source files provide 2 different move functions that can be passed to the **playHangman** function.

* **userMove** is an interactive move function that expects a user to play the game using stdin and stdout.
* **randomMove** is a computer move function that randomly picks a letter from the list of letters that have not been guessed yet. It's quite useless in its current state, but it demonstrates the concept.

The goal of these pluggable move functions is to demonstrate the ability to add additional move functions that could offer more intelligent or interesting moves for fun and educational purposes.

## Next Steps

Although my main goal is to work on other projects, I do plan to refactor and improve this code from time-to-time as I become a better C programmer.

A few tasks I have in mind:

* **Write tests.** This is something I haven't learned to do in C with JetBrains CLion yet.
* **Create Doxygen Documentation.** I wrote the comments and would like to see the documentation generated.
* **Add logging.** Good practice for production quality apps.
* **Improve input and function argument validation.** I think this can always be improved in any application.

As far as new features, it would be fun to do the following:

* **Read secret words from a file, user input, etc.**
* **Load and save games.**
* **Maintain player profiles and statistics.**
* **Develope other move functions with more intelligence.**

## Code

The C code is written with **JetBrains CLion**.


