#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1;
    } else {
        int leftPile = numCrates / 2;
        int rightPile = numCrates - leftPile;
        return numTrucks(leftPile, loadSize) + numTrucks(rightPile, loadSize);
    }
}
