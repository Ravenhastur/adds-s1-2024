// Computer.cpp
#include "Computer.h"
#include "Rock.h" // Include move headers here
// Include other move headers as well

Move* Computer::makeMove() {
    // Computer always plays Rock for simplicity
    return new Rock();
}

string Computer::getName() {
    return "Computer";
}
