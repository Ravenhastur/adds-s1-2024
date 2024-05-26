 #ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>

class DocumentManager {
private:
    // Internal class to represent a document
    struct Document {
        std::string name;
        int id;
        int license_limit;
        std::unordered_set<int> borrowedBy; // Set of patron IDs who have borrowed this document

        Document(const std::string& name, int id, int license_limit)
            : name(name), id(id), license_limit(license_limit) {}
    };

    std::unordered_map<std::string, int> nameToDocID; // Map document name to document ID
    std::unordered_map<int, Document> docIDToDocument; // Map document ID to Document object
    std::unordered_set<int> patrons; // Set of registered patrons

public:
    void addDocument(const std::string& name, int id, int license_limit);
    void addPatron(int patronID);
    int search(const std::string& name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);
};

#endif // DOCUMENT_MANAGER_H