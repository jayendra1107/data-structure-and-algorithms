// This class creates a linked list data type. We can call this file in any other file using ' #include "Node .cpp" ' to use Node data type.
class Node {
public:
    int data;
    Node *next;
    Node (int data) {
        this -> data = data;
        next = nullptr;
    }
};
