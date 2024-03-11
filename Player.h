#ifndef PLAYER_FILE
#define PLAYER_FILE

#include "Move.h"

#include <string>
using namespace std;

class Player {
    private:
    string name;
public:
Player(){};
Player(string name);
    virtual Move* makeMove() = 0;
    virtual string getName() = 0;
};

#endif // PLAYER_H
