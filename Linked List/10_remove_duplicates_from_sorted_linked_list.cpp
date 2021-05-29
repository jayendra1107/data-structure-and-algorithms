// Program to remove duplicates from sorted linked list

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

// Removing duplicates from sorted linked list
void remove_duplicates(Node *head) {
    Node *curr = head;
    while(curr != nullptr && curr->next != nullptr) {
        if(curr->data == curr->next->data) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else {
            curr = curr->next;
        }
    }
}

int main() {
    Node *head = take_input();
    remove_duplicates(head);
    print (head);
    cout<<endl;
    return 0;
}
