// Referee.cpp
#include "Referee.h"
#include "Move.h"

Referee::Referee() {
    // Initialize any needed variables
}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    if (move1->beats(move2)) {
        return player1;
    } else if (move2->beats(move1)) {
        return player2;
    } else {
        // Handle tie
        // For now, let's return nullptr to indicate a tie
        return nullptr;
    }
}