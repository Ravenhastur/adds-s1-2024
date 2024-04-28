#include <iostream>
#include "LinkedList.h"
#include <limits>
#include "Node.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    head = nullptr;
    for (int i = 0; i < len; i++) {
        insertPosition(i + 1, array[i]);
    }
}

LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->link;
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node;
    newNode->data = newNum;
    newNode->link = nullptr;

    if (pos <= 1) {
        newNode->link = head;
        head = newNode;
    } else {
        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
            curr = curr->link;
        }

        if (curr == nullptr) {
            Node* tail = head;
            while (tail->link != nullptr) {
                tail = tail->link;
            }
            tail->link = newNode;
        } else {
            newNode->link = curr->link;
            curr->link = newNode;
        }
    }
}

bool LinkedList::deletePosition(int pos) {
    if (pos <= 0 || head == nullptr) {
        return false;
    }

    Node* curr = head;
    if (pos == 1) {
        head = curr->link;
        delete curr;
        return true;
    }

    for (int i = 1; i < pos - 1 && curr->link != nullptr; i++) {
        curr = curr->link;
    }

    if (curr->link == nullptr) {
        return false;
    }

    Node* temp = curr->link;
    curr->link = temp->link;
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* curr = head;
    for (int i = 1; i < pos && curr != nullptr; i++) {
        curr = curr->link;
    }

    if (curr == nullptr) {
        return std::numeric_limits<int>::max();
    }

    return curr->data;
}

int LinkedList::search(int target) {
    Node* curr = head;
    int pos = 1;
    while (curr != nullptr) {
        if (curr->data == target) {
            return pos;
        }
        curr = curr->link;
        pos++;
    }
    return -1;
}

void LinkedList::printList() {
    std::cout << "[";
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data;
        curr = curr->link;
        if (curr != nullptr) {
            std::cout << " ";
        }
    }
    std::cout << "]";
}