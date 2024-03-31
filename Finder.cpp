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

//     for(uint idx = s2.size() - 1; idx = 0; idx--){
        
//     }
// }

#include "Finder.h"

#include <iostream>

using namespace std;

std::vector<int> computeLPSArray(std::string pat) {
    int m = pat.size();
    std::vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {
    std::vector<int> result;
    int n = s1.size();
    int m = s2.size();

    std::vector<int> lps = computeLPSArray(s2);

    int i = 0, j = 0;
    while (i < n) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && s1[i] != s2[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}