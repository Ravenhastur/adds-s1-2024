#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    TrieNode* curr = root;
    int routerNumber = -1;

    for (int i = 0; i < networkAddress.length(); i++) {
        int index = networkAddress[i] - '0';
        if (curr->children[index] == nullptr) {
            break;
        }
        curr = curr->children[index];
        if (curr->routerNumber != -1) {
            routerNumber = curr->routerNumber;
        }
    }

    return routerNumber;
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    insertUtil(root, address, 0, routerNumber);
}

void PrefixMatcher::insertUtil(TrieNode* node, std::string& address, int index, int routerNumber) {
    if (index == address.length()) {
        node->routerNumber = routerNumber;
        return;
    }

    int bit = address[index] - '0';
    if (node->children[bit] == nullptr) {
        node->children[bit] = new TrieNode();
    }

    insertUtil(node->children[bit], address, index + 1, routerNumber);
}