#ifndef HUMAN_FILE
#define HUMAN_FILE

#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

class Human : public Player{
    public:
        Human();
        Human(std::string humanName);
        virtual Move* makeMove() = 0;
        
};

#endif