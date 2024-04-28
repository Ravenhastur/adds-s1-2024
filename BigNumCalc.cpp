#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> bigNum;
    for (char c : numString) {
        if (isdigit(c)) {
            bigNum.push_front(c - '0');
        }
    }
    return bigNum;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    return addLargeDigits(num1, num2);
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    return subLargeDigits(num1, num2);
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry = 0;
    int multiplier = num2.front();
    num2.pop_front();

    for (int digit : num1) {
        int product = digit * multiplier + carry;
        result.push_back(product % 10);
        carry = product / 10;
    }

    if (carry) {
        result.push_back(carry);
    }

    return result;
}

std::list<int> BigNumCalc::addLargeDigits(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry = 0;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend()) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1++;
        }
        if (it2 != num2.rend()) {
            sum += *it2++;
        }
        result.push_front(sum % 10);
        carry = sum / 10;
    }

    if (carry) {
        result.push_front(carry);
    }

    return result;
}

std::list<int> BigNumCalc::subLargeDigits(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int borrow = 0;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();

    while (it1 != num1.rend()) {
        int diff = *it1 - borrow;
        if (it2 != num2.rend()) {
            diff -= *it2++;
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
        it1++;
    }

    while (!result.empty() && result.front() == 0) {
        result.pop_front();
    }

    return result;
}