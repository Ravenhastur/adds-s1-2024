#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> result;
    for (char digit : numString) {
        result.push_back(digit - '0');  // Convert char to int and add to the list
    }
    return result;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> sum;
    int carry = 0;

    while (!num1.empty() || !num2.empty() || carry != 0) {
        int digitSum = carry;

        if (!num1.empty()) {
            digitSum += num1.back();
            num1.pop_back();
        }

        if (!num2.empty()) {
            digitSum += num2.back();
            num2.pop_back();
        }

        carry = digitSum / 10;
        digitSum %= 10;
        sum.push_front(digitSum);
    }

    return sum;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> difference;
    int borrow = 0;

    while (!num1.empty() || !num2.empty()) {
        int digitDiff = borrow;

        if (!num1.empty()) {
            digitDiff += num1.back();
            num1.pop_back();
        }

        if (!num2.empty()) {
            digitDiff -= num2.back();
            num2.pop_back();
        }

        if (digitDiff < 0) {
            digitDiff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        difference.push_front(digitDiff);
    }

    // Remove leading zeroes
    while (!difference.empty() && difference.front() == 0) {
        difference.pop_front();
    }

    return difference;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    int singleDigit = num2.front();
    num2.pop_front();

    std::list<int> product;
    int carry = 0;

    while (!num1.empty() || carry != 0) {
        int digitProduct = carry;

        if (!num1.empty()) {
            digitProduct += num1.back() * singleDigit;
            num1.pop_back();
        }

        carry = digitProduct / 10;
        digitProduct %= 10;
        product.push_front(digitProduct);
    }

    // Remove leading zeroes
    while (!product.empty() && product.front() == 0) {
        product.pop_front();
    }

    return product;
}