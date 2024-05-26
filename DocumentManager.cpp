// DocumentManager.cpp
#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    documents[name] = {id, license_limit, 0};
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name) {
    auto it = documents.find(name);
    return (it != documents.end()) ? it->second.id : 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.find(patronID) == patrons.end()) {
        return false;
    }

    auto it = documents.find(docid);
    if (it == documents.end() || it->second.current_borrowers >= it->second.license_limit) {
        return false;
    }

    borrowed_documents[docid].insert(patronID);
    it->second.current_borrowers++;
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto it = borrowed_documents.find(docid);
    if (it != borrowed_documents.end()) {
        it->second.erase(patronID);
        documents[docid].current_borrowers--;
    }
}