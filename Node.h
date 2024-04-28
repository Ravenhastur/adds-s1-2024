#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
    private:
        int data;
        Node* link;
    public:
        Node(int data, Node* link);
        int getData();
        Node* getLink();
        void setLink(Node* newLink);
};

#endif
