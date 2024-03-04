#include <iostream>
#include <vector>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

using namespace std;

int main() {
    Human me("Mei");
    Computer computer;
    Referee referee;

    Player* winner = referee.refGame(&me, &computer);

    if (winner == nullptr) {
        cout << "It's a Tie" << endl;
    } else {
        cout << winner->getName() << " Wins" << endl;
    }

    return 0;
}
