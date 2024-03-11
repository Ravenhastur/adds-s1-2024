#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player(string name){
    this->name = name;
};

Move* Player::makeMove(){
    return 0;
};

string Player::getName(){
    return this->name;
};