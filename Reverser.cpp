#include "Reverser.h"

int Reverser::reverseDigit(int value) {
    if (value < 0) {
        return -1; // Invalid input
    }
    return reverseDigitHelper(value, 0);
}

int Reverser::reverseDigitHelper(int value, int reversed) {
    if (value == 0) {
        return reversed;
    }
    return reverseDigitHelper(value / 10, reversed * 10 + value % 10);
}

std::string Reverser::reverseString(std::string characters) {
    if (characters.empty()) {
        return "ERROR"; // Invalid input
    }
    return reverseStringHelper(characters, characters.length() - 1);
}

std::string Reverser::reverseStringHelper(const std::string& characters, int index) {
    if (index == 0) {
        return std::string(1, characters[index]);
    }
    return characters[index] + reverseStringHelper(characters, index - 1);
}
