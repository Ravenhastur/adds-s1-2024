#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Player* human = new Human("Mei");
    Player* computer = new Computer();
    Referee referee;

    Player* winner = referee.refGame(human, computer);
    if (winner != nullptr) {
        std::cout << "The winner is: " << winner->getName() << std::endl;
    }

    delete human;
    delete computer;

    return 0;
}