vector<int> Finder::findSubstrings(string s1, string s2)
{
    vector<int> result;
    string prevSubstring;  // Store the previous substring
    size_t prevFound = string::npos;  // Result of the previous search
    size_t currFound = string::npos;  // Result of the current search

    for (size_t i = 1; i <= s2.size(); i++) {
        string currSubstring = s2.substr(0, i);  // Store the current substring

        if (currSubstring != prevSubstring) {
            currFound = s1.find(currSubstring);  // Search only if the substring changes
        }

        if (currFound != string::npos) {
            result.push_back(currFound);
        } else {
            result.push_back(-1);
        }

        prevSubstring = currSubstring;  // Update the previous substring
        prevFound = currFound;  // Update the previous search result
    }

    return result;
}
