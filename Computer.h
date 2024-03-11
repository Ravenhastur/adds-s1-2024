#ifndef COMPUTER_FILE
#define COMPUTER_FILE
#include <iostream>
#include "Player.h"

class Computer : public Player {
public:
    Computer():Player("Computer") {};
    Move* makeMove() ;
    
};

#endif // COMPUTER_H
