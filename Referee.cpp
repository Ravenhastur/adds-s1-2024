#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();
    // Implement logic to determine the winner based on moves
    // Return the winning player or nullptr for a tie
    return nullptr; // Placeholder
}

}
