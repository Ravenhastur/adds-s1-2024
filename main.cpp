#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

using namespace std;

int main() {
    Human human("Human");
    Computer computer;

    Referee referee;

    // Get moves from players
    Move* move1 = human.makeMove();
    Move* move2 = computer.makeMove();

    // Print player names and their moves
    cout << "Human " << move1->getName() << endl;
    cout << "Computer " << move2->getName() << endl;

    // Determine the winner
    Player* winner = referee.refGame(&human, &computer);

    if (winner == nullptr) {
        cout << "Tie" << endl;
    } else {
        cout << winner->getName() << " Wins" << endl;
    }

    // Free memory
    delete move1;
    delete move2;

    return 0;
}
