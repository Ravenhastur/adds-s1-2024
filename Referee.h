// Referee.h
#ifndef REFEREE_H
#define REFEREE_H

#include "Human.h"

class Referee {
public:
    Referee();
    Human* refGame(Human* human1, Human* human2);
};

#endif // REFEREE_H
