
#include "Human.h"
#include "Paper.h"
#include "Scissors.h"
#include "Rock.h"
#include "Robot.h"
#include "Monkey.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"
#include <iostream>
#include <string>

using namespace std;

Human::Human() : Player ("Human") {};
Human::Human(string name) : Player (name) {};

Move* Human::makeMove()
{
    string result;
    cin >> result;
    if (result == "Rock"){

        Move* rockMove = new Rock();
        return rockMove; 

    } else if(result == "Paper"){

        Move* rockMove = new Paper();
        return rockMove; 

    } else if(result == "Scissors"){

        Move* rockMove = new Scissors();
        return rockMove; 

    } else if(result == "Robot"){

        Move* rockMove = new Robot();
        return rockMove; 

    } else if(result == "Monkey"){

        Move* rockMove = new Monkey();
        return rockMove; 

    } else if(result == "Pirate"){

        Move* rockMove = new Pirate();
        return rockMove; 

    } else if(result == "Ninja"){

        Move* rockMove = new Ninja();
        return rockMove; 

    } else if(result == "Zombie"){

        Move* rockMove = new Zombie();
        return rockMove; 

    } 
    cout << "pass" << " ";
    return nullptr;
    
}