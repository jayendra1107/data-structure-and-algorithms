// Program to find the middle element

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

// Finding Middle element of Linked List
Node *mid_of_linked_list(Node *head) {
    if(head == nullptr) {
        return head;
    }
    Node *mid = head;
    Node *end = head;
    while(end != nullptr && end->next != nullptr) {
        mid = mid->next;
        end = end->next->next;
    }
    return mid;
}

// Main Function
int main() {
    Node *head = take_input();
    Node *mid = mid_of_linked_list(head);
    if(mid != nullptr) {
        cout<< mid->data ;
    }
    cout<<endl;
}
