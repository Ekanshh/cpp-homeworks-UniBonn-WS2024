#ifndef GNG_HPP_
#define GNG_HPP_

const int RANGE_FROM = 0;
const int RANGE_TO = 99;

/**
 * @brief This function that will generate an integer random number between a minimum
 * and a maximum value.
 *
 * @param range_from minimum value of the range.
 * @param range_to maximum value of the range.
 * @return int generated random number.
 */
int GetRandomNumber(int range_from, int range_to);

/**
 * @brief This function will interact with the user to play the game.
 *
 * @param num_to_guess number to guess.
 * @param range_from minimum value of the range.
 * @param range_to maximum value of the range.
 * @return EXIT_SUCCESS if the user guessed the number, EXIT_FAILURE otherwise.
 */
int PlayGame(int num_to_guess, int range_from, int range_to);

#endif  // GNG_HPP_
