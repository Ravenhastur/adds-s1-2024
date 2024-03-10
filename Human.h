#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player {
private:
    string name;

public:
    Human(string name = "Human");
    Move* makeMove() override;
    string getName() override;
};

#endif // HUMAN_H
