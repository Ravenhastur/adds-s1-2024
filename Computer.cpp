#include "Computer.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

Computer::Computer() {
    // Seed the random number generator with current time
    srand(time(nullptr));
}

Move* Computer::makeMove() {
    // Generate a random number between 0 and 7 (inclusive)
    int randomMove = rand() % 8;
    // Implement logic to return corresponding move object based on random number
    return nullptr; // Placeholder
}

std::string Computer::getName() {
    return "Computer";
}
