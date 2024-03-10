#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {
public:
Computer():Player("Computer") {};
    Move* makeMove() ;
    
};

#endif // COMPUTER_H
