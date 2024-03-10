// Computer.cpp
#include "Computer.h"
#include "Rock.h"

Move* Computer::makeMove() {
    // Computer always plays Rock for simplicity
    return  new Rock();
}

string Computer::getName() {
    return "Computer";
}
