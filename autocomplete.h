#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <vector>

const int ALPHABET_SIZE = 26;

// Trie Node
struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

// Autocomplete Class
class Autocomplete {
private:
    TrieNode* root;

public:
    Autocomplete();

    void insert(std::string word);

    std::vector<std::string> getSuggestions(std::string partialWord);

private:
    void collectWords(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);
};

#endif  // AUTOCOMPLETE_H