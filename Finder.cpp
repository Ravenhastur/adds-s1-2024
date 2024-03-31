#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    for(uint i = 1; i <= s2.size(); i++){
        int found = s1.find(s2.substr(0, i));

        if (found != string::npos) {
            result.push_back(found);
        } else {
            result.push_back(-1);
        }
    }
    return result;
}

