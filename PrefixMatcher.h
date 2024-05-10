#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <iostream>
#include <string>

const int BITS_IN_IPV4 = 32;
const int BITS_IN_IPV6 = 128;

// Trie Node
struct TrieNode {
    TrieNode* children[2]; // Assuming addresses are binary (0 or 1)
    int routerNumber;      // Router number associated with the node

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        routerNumber = -1; // Initialize router number to -1 (invalid)
    }
};

class PrefixMatcher {
private:
    TrieNode* root;

public:
    PrefixMatcher();
    int selectRouter(std::string networkAddress);
    void insert(std::string address, int routerNumber);

private:
    void insertUtil(TrieNode* node, std::string& address, int index, int routerNumber);
};

#endif  // PREFIXMATCHER_H
