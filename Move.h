// #ifndef MOVE_H
// #define MOVE_H

// #include <string>
// using namespace std;

// class Move {
// public:
//     virtual string getName() = 0;
//     virtual ~Move() {}
// };

// #endif // MOVE_H

// Move.h
#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
public:
    virtual std::string getName() = 0;
    virtual bool beats(Move* move) = 0;
};

#endif // MOVE_H