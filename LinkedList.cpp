#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for (int i = len - 1; i >= 0; i--) {
        insertPosition(1, array[i]);
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->link;
        delete current;
        current = next;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 0) {
        pos = 1;
    }

    Node* newNode = new Node(newNum);

    if (head == nullptr || pos == 1) {
        newNode->link = head;
        head = newNode;
    } else {
        Node* current = head;
        int count = 1;
        while (count < pos - 1 && current->link != nullptr) {
            current = current->link;
            count++;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr || pos <= 0) {
        return false;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->link;
        delete temp;
        return true;
    }

    Node* current = head;
    int count = 1;
    while (count < pos - 1 && current->link != nullptr) {
        current = current->link;
        count++;
    }

    if (current->link == nullptr) {
        return false;
    }

    Node* temp = current->link;
    current->link = current->link->link;
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    if (head == nullptr || pos <= 0) {
        return std::numeric_limits<int>::max();
    }

    Node* current = head;
    int count = 1;
    while (count < pos && current != nullptr) {
        current = current->link;
        count++;
    }

    if (current == nullptr) {
        return std::numeric_limits<int>::max();
    }

    return current->data;
}

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        if (current->data == target) {
            return index;
        }
        current = current->link;
        index++;
    }
    return -1;
}

void LinkedList::printList() {
    Node* current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->link != nullptr) {
            std::cout << " ";
        }
        current = current->link;
    }
    std::cout << "]" << std::endl;
}