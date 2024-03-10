#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    // Determine the names of the moves made by players
    string moveName1 = move1->getName();
    string moveName2 = move2->getName();

    // Determine the winner based on the moves
    // Add your logic here to determine the winner
    // According to the rules of the Moropinzee game

    // Temporary logic: Assume it's a tie for now
    Player* winner = nullptr;

    // Free memory
    delete move1;
    delete move2;

    return winner;
}
