// RecursiveBinarySearch.cpp
#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> list, int target) {
    return recursiveSearch(list, target, 0, list.size() - 1);
}

bool RecursiveBinarySearch::recursiveSearch(std::vector<int>& list, int target, int start, int end) {
    if (start > end) {
        return false;
    }
    int mid = start + (end - start) / 2;
    if (list[mid] == target) {
        return true;
    } else if (list[mid] > target) {
        return recursiveSearch(list, target, start, mid - 1);
    } else {
        return recursiveSearch(list, target, mid + 1, end);
    }
}