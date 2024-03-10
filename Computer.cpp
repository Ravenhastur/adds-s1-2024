#include "Computer.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Constructor definition
Computer::Computer() {}

Move* Computer::makeMove() {
    // Seed the random number generator with current time
    srand(time(nullptr));

    // Generate a random number between 0 and 7 (inclusive)
    int randomMove = rand() % 8;

    // Return corresponding move object based on random number
    switch (randomMove) {
        case 0:
            return new Rock();
        case 1:
            return new Paper();
        case 2:
            return new Scissors();
        case 3:
            return new Monkey();
        case 4:
            return new Robot();
        case 5:
            return new Pirate();
        case 6:
            return new Ninja();
        case 7:
            return new Zombie();
        default:
            return nullptr; // This should never happen
    }
}

string Computer::getName() {
    return "Computer";
}
