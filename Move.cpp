

#include "Move.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Move::Move(string name, vector<string> newCounterMove){

    this-> name = name;
    this->counterMove = newCounterMove;

}

string Move::getName(){

    return this->name;

}

vector<string> Move::getCounterName(){

    return this->counterMove;
}
