// HUamn .h
#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "Move.h"
using namespace std;

class Human {
public:
    virtual Move* makeMove() = 0;
    virtual string getName() = 0;
};

#endif // HUAMN_H
