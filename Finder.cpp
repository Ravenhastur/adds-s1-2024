// #include "Finder.h"

// using namespace std;

// vector<int> Finder::findSubstrings(string s1, string s2) {
//     vector<int> result;
//     for(uint i = 1; i <= s2.size(); i++){
//         int found = s1.find(s2.substr(0, i));

//         if (found != string::npos) {
//             result.push_back(found);
//         } else {
//             result.push_back(-1);
//         }
//     }
//     return result;
// }

#include "Finder.h"
#include <vector>

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    int n = s2.size();
    int pos = 0;

    for (int i = 0; i < n; i++) {
        string prefix = s2.substr(0, i + 1);
        int found = s1.find(prefix, pos);

        if (found == string::npos) {
            result.push_back(-1);
            break; // No need to search for longer prefixes
        } else {
            result.push_back(found);
            pos = found + 1; // Start searching from the next position
        }
    }

    return result;
}
