#include "Finder.h"
#include <vector>

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    int n = s2.size();
    size_t pos = 0;

    for (int i = 0; i < n; i++) {
        string prefix = s2.substr(0, i + 1);
        size_t found = s1.find(prefix, pos);

        if (found == string::npos) {
            result.push_back(-1);
            break; // No need to search for longer prefixes
        } else {
            result.push_back(found);
            pos = found + 1; // Start searching from the next position
        }
    }

    // If the loop finished without finding any prefix, add -1 for the remaining prefixes
    while (result.size() < n) {
        result.push_back(-1);
    }

    return result;
}