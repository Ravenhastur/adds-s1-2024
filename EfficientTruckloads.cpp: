#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    return numTrucksHelper(numCrates, loadSize);
}

int EfficientTruckloads::numTrucksHelper(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1;
    }
    if (memo.find(numCrates) != memo.end()) {
        return memo[numCrates];
    }
    int leftPile = numCrates / 2;
    int rightPile = numCrates - leftPile;
    int result = numTrucksHelper(leftPile, loadSize) + numTrucksHelper(rightPile, loadSize);
    memo[numCrates] = result;
    return result;
}
