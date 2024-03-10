#ifndef MOVE_FILE
#define MOVE_FILE

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Move{
    private:
        string name;
        vector<string> counterMove{"Empty", "Empty"};
    public:
        Move(){};
        Move(string name, vector<string> counterMove);
        string getName();
        vector<string> getCounterName();
        
};

#endif