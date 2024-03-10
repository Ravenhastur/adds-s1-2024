#ifndef MOVE_H
#define MOVE_H

#include <string>
using namespace std;

class Move {
public:
    virtual string getName() = 0;
    virtual ~Move() {}
};

// Assuming all move classes are defined in the same file

class Rock : public Move {
public:
    string getName() override {
        return "Rock";
    }
};

class Paper : public Move {
public:
    string getName() override {
        return "Paper";
    }
};

class Scissors : public Move {
public:
    string getName() override {
        return "Scissors";
    }
};

class Monkey : public Move {
public:
    string getName() override {
        return "Monkey";
    }
};

class Robot : public Move {
public:
    string getName() override {
        return "Robot";
    }
};

class Pirate : public Move {
public:
    string getName() override {
        return "Pirate";
    }
};

class Ninja : public Move {
public:
    string getName() override {
        return "Ninja";
    }
};

class Zombie : public Move {
public:
    string getName() override {
        return "Zombie";
    }
};

#endif // MOVE_H
