#ifndef REVERSER_H
#define REVERSER_H

#include <string>
using std::string;
class Reverser {
public:
    int reverseDigit(int value);
    std::string reverseString(std::string characters);
private:
    int reverseDigitHelper(int value, int reversed);
    std::string reverseStringHelper(const std::string& characters, int index);
};

#endif // REVERSER_H
