#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <iostream>

class Human : public Player {
private:
    std::string name;

public:
    Human(std::string playerName = "Human");
    char makeMove();
    std::string getName();
};

#endif