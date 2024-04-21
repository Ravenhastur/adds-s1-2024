// main.cpp
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> list;
    int num;
    while (iss >> num) {
        list.push_back(num);
    }

    QuickSort quickSort;
    list = quickSort.sort(list);

    RecursiveBinarySearch binarySearch;
    bool found = binarySearch.search(list, 1); // Change the search target to 0

    std::cout << (found ? "true" : "false") << " ";
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}