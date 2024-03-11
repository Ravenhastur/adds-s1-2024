#include "Computer.h"
#include "Human.h"
#include "Referee.h"
#include "Player.h"
#include <iostream>

int main(){

    Player** players = new Player* [2];
    players[0] = new Human("Jason");
    players[1] = new Computer;

    Referee referee;

    Player* winner = referee.refGame(players[0], players[1]);

    if (winner != nullptr) {

        cout << winner->getName() << " Wins." << endl;

    } else {

        cout << "It's a Tie." << endl;
    }

    return 0;

}