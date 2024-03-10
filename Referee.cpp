#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    string moveName1 = move1->getName();
    string moveName2 = move2->getName();

    // Logic to determine the winner based on the moves
    // Assuming Moropinzee rules implementation
    // Add your logic here

    // Temporary logic: Assume it's a tie for now
    Player* winner = nullptr;

    delete move1;
    delete move2;

    return winner;
}
