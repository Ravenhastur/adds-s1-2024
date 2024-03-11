
#ifndef REFEREE_FILE
#define REFEREE_FILE

#include "Player.h"

class Referee {
public:
    Referee(){};
    Player* refGame(Player* player1, Player* player2);
};

#endif // REFEREE_H
