#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

class Human : public Player{
    public:
        Human();
        Human(std::string humanName);
        Move* makeMove();
        
};

#endif