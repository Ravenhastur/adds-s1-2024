#include "DocumentManager.h"

void DocumentManager::addDocument(const std::string& name, int id, int license_limit) {
    nameToDocID[name] = id;
    docIDToDocument[id] = Document(name, id, license_limit);
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(const std::string& name) {
    auto it = nameToDocID.find(name);
    return (it != nameToDocID.end()) ? it->second : 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.count(patronID) == 0)
        return false; // Invalid patron ID

    auto& doc = docIDToDocument[docid];
    if (doc.borrowedBy.size() >= doc.license_limit)
        return false; // Reached license limit

    doc.borrowedBy.insert(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto& doc = docIDToDocument[docid];
    doc.borrowedBy.erase(patronID);
}