#include "Finder.h"

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2)
{
    std::vector<int> result;
    std::string prevSubstring;
    size_t prevFound = std::string::npos;
    size_t currFound = std::string::npos;

    for (size_t i = 1; i <= s2.size(); i++) {
        std::string currSubstring = s2.substr(0, i);

        if (currSubstring != prevSubstring) {
            currFound = s1.find(currSubstring);
        }

        if (currFound != std::string::npos) {
            result.push_back(currFound);
        } else {
            result.push_back(-1);
        }

        prevSubstring = currSubstring;
        prevFound = currFound;
    }

    return result;
}