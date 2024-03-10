// Referee.cpp
#include "Referee.h"

Referee::Referee() {}

Human* Referee::refGame(Human* human1, Human* human2) {
    Move* move1 = human1->makeMove();
    Move* move2 = human2->makeMove();

    // Logic to determine winner based on moves

    delete move1;
    delete move2;

    return nullptr; // Temporary return value, replace with actual logic
}
