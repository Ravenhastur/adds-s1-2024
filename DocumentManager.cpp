#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    Document document;
    document.id = id;
    document.license_limit = license_limit;
    document.current_borrowers = 0;
    documents[name] = document;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name) {
    if (documents.count(name) > 0) {
        return documents[name].id;
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (documents.count(docid) > 0 && patrons.count(patronID) > 0) {
        Document& document = documents[docid];
        if (document.current_borrowers < document.license_limit) {
            borrowed_documents[patronID].insert(docid);
            document.current_borrowers++;
            return true;
        }
    }
    return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if (documents.count(docid) > 0 && patrons.count(patronID) > 0) {
        Document& document = documents[docid];
        if (borrowed_documents[patronID].count(docid) > 0) {
            borrowed_documents[patronID].erase(docid);
            document.current_borrowers--;
        }
    }
}