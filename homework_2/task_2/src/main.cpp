#include <cstdlib>
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        std::cerr << "Invalid number of arguments. Must be 2." << std::endl;
        return EXIT_FAILURE;
    }

    std::stringstream file_1{argv[1]};
    std::stringstream file_2{argv[2]};

    int number_1 = 0;
    int number_2 = 0;
    std::string ext_1;
    std::string ext_2;

    file_1 >> number_1 >> ext_1;
    file_2 >> number_2 >> ext_2;

    if (ext_1 == ".txt" && ext_2 == ".txt") {
        std::cout << "Both files are text files." << std::endl;
        std::cout << (number_1 + number_2) / 2.0 << std::endl;
    } else if (ext_1 == ".png" && ext_2 == ".png") {
        std::cout << "Both files are png files." << std::endl;
        std::cout << (number_1 + number_2) << std::endl;
    } else if (ext_1 == ".txt" && ext_2 == ".png") {
        std::cout << "Files are different." << std::endl;
        std::cout << (number_1 % number_2) << std::endl;
    } else {
        std::cerr << "Invalid files. Must be of the following type:= both txt, both png or first "
                     "txt and second png."
                  << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}