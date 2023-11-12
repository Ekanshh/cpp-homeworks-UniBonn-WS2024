#include "gng.hpp"

int main() {
    int num_to_guess = GNGFunc::GetRandomNumber(GNGConst::RANGE_FROM, GNGConst::RANGE_TO);
    return GNGFunc::PlayGame(num_to_guess, GNGConst::RANGE_FROM, GNGConst::RANGE_TO);
}