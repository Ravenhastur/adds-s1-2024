// QuickSort.cpp
#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list) {
    quickSort(list, 0, list.size() - 1);
    return list;
}

void QuickSort::quickSort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pivot = partition(list, low, high);
        quickSort(list, low, pivot - 1);
        quickSort(list, pivot + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    int pivot;
    if (high - low + 1 >= 3) {
        pivot = list[low + 2];
    } else {
        pivot = list[low];
    }
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
        } while (list[i] < pivot);
        do {
            j--;
        } while (list[j] > pivot);
        if (i >= j) {
            return j;
        }
        std::swap(list[i], list[j]);
    }
}