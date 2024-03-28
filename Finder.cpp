#include "Finder.h"

using namespace std;

// vector<int> Finder::findSubstrings(string s1, string s2) {
// vector<int> result;
// for(size_t i = 1; i <= s2.size(); i++) {
// size_t found = s1.find(s2.substr(0, i));
// if (found != string::npos) {
// result.push_back(found);
// } else {
// result.push_back(-1);
// }
// }
// return result;
// }

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    result.reserve(s2.size());  // Reserve space for the result vector

    string substr = s2.substr(0, 1);  // Extract the initial substring

    for (size_t i = 1; i <= s2.size(); i++) {
        size_t found = s1.find(substr);

        if (found != string::npos) {
            result.push_back(found);
        } else {
            result.push_back(-1);
        }

        if (i < s2.size()) {
            substr.push_back(s2[i]);  // Extend the substring
        }
    }

    return result;
}