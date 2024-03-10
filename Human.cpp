#include "Human.h"
#include <iostream>

using namespace std;

Human::Human(string name) : name(name) {}

Move* Human::makeMove() {
    string moveName;
    cout << "Enter Move for " << name << ": ";
    cin >> moveName;

    // Return corresponding move object based on input
    if (moveName == "Rock")
        return new Rock();
    else if (moveName == "Paper")
        return new Paper();
    else if (moveName == "Scissors")
        return new Scissors();
    else if (moveName == "Monkey")
        return new Monkey();
    else if (moveName == "Robot")
        return new Robot();
    else if (moveName == "Pirate")
        return new Pirate();
    else if (moveName == "Ninja")
        return new Ninja();
    else if (moveName == "Zombie")
        return new Zombie();

    return nullptr; // Return nullptr for invalid move
}

string Human::getName() {
    return name;
}

}
