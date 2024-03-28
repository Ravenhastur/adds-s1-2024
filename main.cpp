#include "Finder.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s2[] = { "1", "3", "4" };
    Finder finder;
    std::vector<int> result;
    std::string s1 = "3";

    result = finder.findSubstrings(s1, s2[2]);

for (size_t i = 0; i < result.size(); i++) {
    int value = result[i];
    cout << value << " ";
}
cout << endl;

    return 0;
}