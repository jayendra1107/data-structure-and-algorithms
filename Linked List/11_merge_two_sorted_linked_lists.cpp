// Program to merge two sorted linked lists

#include<iostream>
#include "Node.cpp"
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

// Merge two sorted linked lists
Node *merge_sorted(Node *head1, Node *head2) {
    if(head1 == nullptr && head2 == nullptr) {  // If both linked lists are empty
        return nullptr;
    }
    if(head1 == nullptr) {                      // If head1 is empty 
        return head2;
    }
    if(head2 == nullptr) {                      // If head2 is empty
        return head1;
    }
    Node *curr, *head;
    // Assigning head to minimum head among both the lists
    if(head1->data > head2->data) {
        head = head2;
        head2 = head2->next;
    }
    else {
        head = head1;
        head1 = head1->next;
    }
    curr = head;
    // Appending the linked list with minimum among both
    while(head1 != nullptr && head2 != nullptr) {
        if(head1->data > head2->data) {
            curr->next = head2;
            head2 = head2->next;
        }
        else {
            curr->next = head1;
            head1 = head1->next;
        }
        curr = curr->next;
    }
    // When a linked list reaches end and other one is appended at the end of main list
    if(head1 == nullptr) {
        curr->next = head2;
    }
    else {
        curr->next = head1;
    }
    return head;
}

int main() {
    Node *head1 = take_input();
    Node *head2 = take_input();
    Node *head = merge_sorted(head1, head2);
    print(head);
    cout<<endl;
    return 0;
}
