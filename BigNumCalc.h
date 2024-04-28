#ifndef BIG_NUM_CALC_H
#define BIG_NUM_CALC_H

#include <list>
#include <string>

class BigNumCalc {
public:
    std::list<int> buildBigNum(std::string numString);
    std::list<int> add(std::list<int> num1, std::list<int> num2);
    std::list<int> sub(std::list<int> num1, std::list<int> num2);
    std::list<int> mul(std::list<int> num1, std::list<int> num2);
};

#endif // BIG_NUM_CALC_H