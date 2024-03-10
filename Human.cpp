
#include "Human.h"
#include <iostream>
#include "Rock.h" // Include move headers here
// Include other move headers as well

using namespace std;

Human::Human(string name) : name(name) {}

Move* Human::makeMove() {
    string moveName;
    cout << "Enter Move: ";
    cin >> moveName;

    // Return corresponding move object based on input
    if (moveName == "Rock")
        return new Rock();
    // Handle other moves similarly

    return nullptr; // Return nullptr for invalid move
}

string Human::getName() {
    return name;
}
