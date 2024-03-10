#include "Referee.h"
#include "Player.h"
#include "Move.h"
#include <iostream>
#include <algorithm> 

using namespace std;

Player* Referee::refGame(Player* player1, Player* player2){
    
    Move* p1Res = player1->makeMove();
    Move* p2Res = player2->makeMove();


	vector<string>p1 = p1Res->getCounterName();
    vector<string>p2 = p2Res->getCounterName();

    int p1Win = count(p1.begin(), p1.end(), p2Res->getName()); 
    int p2Win = count(p2.begin(), p2.end(), p1Res->getName()); 
	if (p1Win > 0) {  

        return player1;

    } 
    else if (p2Win > 0){ 

        return player2;
        
    }


return nullptr;

        
}