#include "Computer.h"
#include "Rock.h" // Include move headers here


Move* Computer::makeMove() {
    // Computer always plays Rock for simplicity
    return new Rock();
}

string Computer::getName() {
    return "Computer";
}