#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <vector>
#include <unordered_map>

// TrieNode class to represent each node in the Trie
class TrieNode {
public:
    std::unordered_map<std:::string, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// Autocomplete class
class Autocomplete {
private:
    TrieNode* root;

    // Helper function to traverse the Trie and find words starting with a given prefix
    void traverseTrie(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);

public:
    Autocomplete();

    // Function to return known words that start with partialWord
    std::vector<std::string> getSuggestions(std::string partialWord);

    // Function to add a word to the known words
    void insert(std::string word);
};

#endif // AUTOCOMPLETE_H