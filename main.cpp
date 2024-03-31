#include "Finder.h"

using namespace std;

int main()
{
    string s2[] = { "1", "4", "3" , "2" , "5"};
    Finder finder;
    vector<int> result;
    string s1 = "3";

    for (size_t i = 0; i < sizeof(s2) / sizeof(s2[0]); i++) {
        size_t found = s1.find(s2[i]);
        if (found != string::npos) {
            result.push_back(found);
        } else {
            result.push_back(-1);
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
    int value = result[i];
    cout << value << " ";
}
    cout << endl;

    return 0;
}