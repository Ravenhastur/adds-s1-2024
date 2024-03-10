#include "Human.h"
#include <iostream>

using namespace std;

Human::Human(string name) : name(name) {}

Move* Human::makeMove() {
    string moveName;
    cout << "Enter Move: ";
    cin >> moveName;
    // Assuming input is valid, you might need additional error handling
    return createMove(moveName);
}

string Human::getName() {
    return name;
}
