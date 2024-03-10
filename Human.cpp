#include "Human.h"
#include <iostream>

Human::Human(std::string name) : name(name) {}

Move* Human::makeMove() {
    std::string moveName;
    std::cout << "Enter Move for " << name << ": ";
    std::cin >> moveName;
    // Implement logic to return corresponding move object based on input
    return nullptr; // Placeholder
}

std::string Human::getName() {
    return name;
}
