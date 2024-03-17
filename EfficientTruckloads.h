#ifndef EFFICIENTTRUCKLOADS_H
#define EFFICIENTTRUCKLOADS_H

#include <unordered_map>

class EfficientTruckloads {
public:
    int numTrucks(int numCrates, int loadSize);
private:
    std::unordered_map<int, int> memo;
    int numTrucksHelper(int numCrates, int loadSize);
};

#endif // EFFICIENTTRUCKLOADS_H
