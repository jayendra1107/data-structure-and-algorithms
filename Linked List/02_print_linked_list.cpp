// Program to print linked list

#include <iostream>
using namespace std;

// Creating Node data type
class Node {
public:
    int data;
    Node *next;
    
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Printing Linked List using iteration
void print(Node *head) {
    while(head != nullptr) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Printing Linked List using recursion
void print_using_recursion(Node *head) {
    if(head == nullptr) {
        return;
    }
    cout<<(head->data)<<" ";
    print_using_recursion(head->next);
}

int main() {

    // Statically
    /*
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    n1.next = &n2;
    Node n3(7);
    n2.next = &n3;
    */

    // Dynamically
    Node *head = nullptr;
    Node *n1 = new Node(1);
    head = n1;
    Node *n2 = new Node(2);
    n1 -> next = n2;
    Node *n3 = new Node(7);
    n2 -> next = n3;

    print(head);
    cout<<"\n";
    print_using_recursion(head);
    cout<<"\n";
    return 0;
}
