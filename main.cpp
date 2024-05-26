#include "DocumentManager.h"

int main() {
    // Test the DocumentManager class
    DocumentManager manager;

    // Add some documents
    manager.addDocument("Book 1", 1, 2);
    manager.addDocument("Book 2", 2, 3);

    // Add some patrons
    manager.addPatron(1);
    manager.addPatron(2);
    manager.addPatron(3);

    // Search for a document
    int docid = manager.search("Book 1");
    if (docid != 0) {
        std::cout << "Found document with ID: " << docid << std::endl;
    } else {
        std::cout << "Document not found" << std::endl;
    }

    // Borrow a document
    bool borrowed = manager.borrowDocument(1, 1);
    if (borrowed) {
        std::cout << "Document borrowed successfully" << std::endl;
    } else {
        std::cout << "Failed to borrow document" << std::endl;
    }

    // Return a document
    manager.returnDocument(1, 1);

    return 0;
}