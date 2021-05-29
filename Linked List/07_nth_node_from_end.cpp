// Program to find the nth node from the end

#include<iostream>
using namespace std;
#include "node.cpp" // This line calls the Node.cpp where a class is created to build linked list data type

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

// Returning nth Node from the end of the Linked List
Node *nth_node(Node *head, int &n) {
    Node *curr = head;
    Node *end = head;
    int count = 1;
    if(head == nullptr) {
        return nullptr;
    }
    while(end->next != nullptr) {
        if(count == n) {
            curr = curr->next;
            end = end->next;
        }
        else {
            end = end->next;
            count++;
        }
    }
    if(count != n){
        return nullptr;
    }
    else {
        return curr;
    }
}

// Main Function
int main() {
    Node *head = take_input();
    int n;
    cin>>n;
    Node *nth_element = nth_node(head, n);
    if(nth_element != nullptr) {
        cout<<nth_element->data;
    }
    cout<<endl;
}
