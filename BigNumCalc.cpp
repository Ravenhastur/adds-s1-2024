#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> result;
    for (char digit : numString) {
        result.push_back(digit - '0');  // Convert char to int and add to the list
    }
    return result;
}

std::list<int> BigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> sum;
    int carry = 0;

    std::list<int>::const_reverse_iterator it1 = num1.rbegin();
    std::list<int>::const_reverse_iterator it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend() || carry != 0) {
        int digitSum = carry;

        if (it1 != num1.rend()) {
            digitSum += *it1;
            ++it1;
        }

        if (it2 != num2.rend()) {
            digitSum += *it2;
            ++it2;
        }

        carry = digitSum / 10;
        digitSum %= 10;
        sum.push_front(digitSum);
    }

    return sum;
}

std::list<int> BigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> difference;
    int borrow = 0;

    std::list<int>::const_reverse_iterator it1 = num1.rbegin();
    std::list<int>::const_reverse_iterator it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend()) {
        int digitDiff = borrow;

        if (it1 != num1.rend()) {
            digitDiff += *it1;
            ++it1;
        }

        if (it2 != num2.rend()) {
            digitDiff -= *it2;
            ++it2;
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

std::list<int> BigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> product;

    for (int i = 0; i < num2.size(); ++i) {
        int singleDigit = *(num2.rbegin());
        std::list<int> tempProduct(i, 0);

        int carry = 0;

        std::list<int>::const_reverse_iterator it = num1.rbegin();

        while (it != num1.rend() || carry != 0) {
            int digitProduct = carry;

            if (it != num1.rend()) {
                digitProduct += *it * singleDigit;
                ++it;
            }

            carry = digitProduct / 10;
            digitProduct %= 10;
            tempProduct.push_front(digitProduct);
        }

        product = add(product, tempProduct);

        num2.pop_back();
    }

    // Remove leading zeroes
    while (!product.empty() && product.front() == 0) {
        product.pop_front();
    }

    return product;
}