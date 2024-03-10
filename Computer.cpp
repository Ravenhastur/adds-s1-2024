// Computer.cpp
#include "Computer.h"

Move* Computer::makeMove() {
    // Computer always plays Rock for simplicity
    return new Move();
}

string Computer::getName() {
    return "Computer";
}
