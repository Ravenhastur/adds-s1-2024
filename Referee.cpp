// Referee.cpp
#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    // Logic to determine winner based on moves

    delete move1;
    delete move2;

    return nullptr; // Temporary return value, replace with actual logic
}
