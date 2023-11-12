// Add this line to include the current directory in the search path for header files
#include "gng.hpp"

#include <cstdlib>
#include <iostream>
#include <random>

namespace GNGFunc {
int GetRandomNumber(int range_from, int range_to) {
    std::random_device rand_dev;
    std::mt19937 gen((rand_dev()));
    std::uniform_int_distribution<int> dist(range_from, range_to);

    return dist(gen);
}

int PlayGame(int num_to_guess, int range_from, int range_to) {
    std::cout << "Guess a number between " << range_from << " and " << range_to << std::endl;
    int guess = -1;

    do {
        std::cin >> guess;

        if (std::cin.fail()) {
            std::cerr << "Error encountered, exiting..." << std::endl;
            std::cerr << num_to_guess << std::endl;
            return EXIT_FAILURE;
        }

        if (guess < range_from || guess > range_to) {
            std::cerr << "[WARNING] : Number must be between " << range_from << " and " << range_to
                      << std::endl;
            continue;
        }

        if (guess > num_to_guess) {
            std::cout << "My number is smaller than your guess.. " << std::endl;
        } else if (guess < num_to_guess) {
            std::cout << "My number is larger than your guess..." << std::endl;
        } else {
            std::cout << "Correct! You have won." << std::endl;
            std::cout << num_to_guess << std::endl;
        }
    } while (guess != num_to_guess);

    return EXIT_SUCCESS;
}
}  // namespace GNGFunc