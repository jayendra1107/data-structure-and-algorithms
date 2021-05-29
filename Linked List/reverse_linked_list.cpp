// Program to reverse linked list

#include<iostream>
#include "Node.cpp" // This line calls the Node.cpp where a class is created to build linked list data type
using namespace std;

// Input Linked List
// This function takes input until -1
Node *take_input() {
    int data;
    cin>>data;
    Node *head = nullptr;
    Node *tail = nullptr;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = tail -> next;
            // tail = newNode
        }
        cin>>data;
    }
    return head;
}

// Print Linked List
void print(Node *head) {
    while(head != nullptr) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Reversing the linked list
Node *reverse (Node *head) {
    Node *prev = nullptr;
    Node *curr = head;
    while(curr!=nullptr) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Reversing linked list uding recursion
Node *rev_recursive(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *rest_head = rev_recursive(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = nullptr;
    return rest_head;
}

int main() {
    Node *head = take_input();
    head = rev_recursive(head);
    print(head);
    cout<<endl;
}
