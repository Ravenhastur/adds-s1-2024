// #include "Autocomplete.h"

// Autocomplete::Autocomplete() {
//     root = new TrieNode();
// }

// void Autocomplete::insert(std::string word) {
//     TrieNode* current = root;
//     for (char &c : word) {
//         int index = c - 'a';
//         if (current->children[index] == nullptr) {
//             current->children[index] = new TrieNode();
//         }
//         current = current->children[index];
//     }
//     current->isEndOfWord = true;
// }

// std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
//     std::vector<std::string> suggestions;
//     TrieNode* current = root;
//     for (char &c : partialWord) {
//         int index = c - 'a';
//         if (current->children[index] == nullptr) {
//             return suggestions;
//         }
//         current = current->children[index];
//     }
//     collectWords(current, partialWord, suggestions);
//     return suggestions;
// }

// void Autocomplete::collectWords(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions) {
//     if (node->isEndOfWord) {
//         suggestions.push_back(prefix);
//     }
//     for (int i = 0; i < ALPHABET_SIZE; i++) {
//         if (node->children[i] != nullptr) {
//             char c = 'a' + i;
//             collectWords(node->children[i], prefix + c, suggestions);
//         }
//     }
// }


#include "Autocomplete.h"

// Autocomplete class implementation

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::traverseTrie(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions) {
    if (node == nullptr) return;

    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }

    for (auto& pair : node->children) {
        traverseTrie(pair.second, prefix + pair.first, suggestions);
    }
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> suggestions;
    TrieNode* current = root;

    // Traverse to the node representing the prefix
    for (char c : partialWord) {
        if (current->children.find(c) == current->children.end()) {
            // No words with this prefix, return empty vector
            return suggestions;
        }
        current = current->children[c];
    }

    // Traverse the Trie to find words starting with the given prefix
    traverseTrie(current, partialWord, suggestions);

    return suggestions;
}

void Autocomplete::insert(std::string word) {
    TrieNode* current = root;
    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}