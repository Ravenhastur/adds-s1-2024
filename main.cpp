#include <iostream>
#include "Truckloads.h"
#include "Reverser.h"
using namespace std;

int main() {
    Truckloads truckloads;
    cout << truckloads.numTrucks(14, 3) << endl; 
    Reverser reverser;
    cout << reverser.reverseDigit(1234) << endl;
    cout << reverser.reverseString("hello") << endl;
    return 0;
}
