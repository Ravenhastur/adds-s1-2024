#include "DocumentManager.h"

void DocumentManager::addDocument(const std::string& name, int id, int license_limit) {
    nameToDocID[name] = id;
    docIDToDocument.emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(name, id, license_limit));
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(const std::string& name) {
    auto it = nameToDocID.find(name);
    return (it != nameToDocID.end()) ? it->second : 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    // Check if the patron ID is valid
    if (patrons.count(patronID) == 0)
        return false;

    // Get the reference to the document object
    auto& doc = docIDToDocument.at(docid);

    // Check if the license limit has been reached
    if (static_cast<int>(doc.borrowedBy.size()) >= doc.license_limit)
        return false;

    // Add the patron ID to the set of borrowers
    doc.borrowedBy.insert(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    // Get the reference to the document object
    auto& doc = docIDToDocument.at(docid);

    // Remove the patron ID from the set of borrowers
    doc.borrowedBy.erase(patronID);
}