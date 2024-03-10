#include "Computer.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

Computer::Computer() {
    // Seed the random number generator with current time
    srand(time(nullptr));
}

Move* Computer::makeMove() {
    // Generate a random number between 0 and 7 (inclusive)
    int randomMove = rand() % 8;
    // Assuming all moves are defined in the same file
    return createMove(getMoveName(randomMove));
}

string Computer::getName() {
    return "Computer";
}
