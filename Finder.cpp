#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
vector<int> result;
int found = s1.find(s2);
for(size_t i = found; i <= s2.size(); i++) {
size_t found = s1.find(s2.substr(0, i));
if (found != string::npos) {
result.push_back(found);
} else {
result.push_back(-1);
}
}
return result;
}

