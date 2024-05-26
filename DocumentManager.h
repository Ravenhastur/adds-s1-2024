// DocumentManager.h
#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

struct Document {
    int id;
    int license_limit;
    int current_borrowers;
};

class DocumentManager {
public:
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);

private:
    std::unordered_map<std::string, Document> documents;
    std::unordered_set<int> patrons;
    std::unordered_map<int, std::set<int>> borrowed_documents;
};

#endif // DOCUMENT_MANAGER_H