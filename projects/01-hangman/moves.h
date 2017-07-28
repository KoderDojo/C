/*****************************************************
 *
 * Various move functions that can be plugged into
 * the hangman game to allow various personas to
 * play the game. Currently the game comes with
 * two move functions:
 *
 * userMove - interactive user that responds to
 * input and output using stdin and stdout.
 *
 * randomMove - computer chooses a random
 * letter from a list of available letters.
 *
 ****************************************************/


#include "hangman.h"

#ifndef HANGMAN_MOVES_H
#define HANGMAN_MOVES_H

/// User chooses letters via stdin and stdout.
/// The available letters are displayed prior
/// to this function being called.
///
/// This function is required to provide a
/// valid letter. Currently, this means the
/// letter must be available and LOWERCASE.
///
/// \param board The hangman board.
/// \return The letter chosen by the user.
char userMove(Board board);


/// Computer choose a random available letter.
/// The available letters are obtained from
/// the 'getAvailableLetters' function.
///
/// This function is required to provide a
/// valid letter. Currently, this means the
/// letter must be available and LOWERCASE.
///
/// \param board The hangman board.
/// \return Random letter chosen by computer.
char randomMove(Board board);

#endif //HANGMAN_MOVES_H
