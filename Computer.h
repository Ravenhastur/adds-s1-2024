// Computer.h
#ifndef COMPUTER_H
#define COMPUTER_H

#include "Human.h"

class Computer : public Player {
public:
    Move* makeMove() override;
    string getName() override;
};

#endif // COMPUTER_H
