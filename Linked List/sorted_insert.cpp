// Program to insert element in sorted linked list

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

// Inserting Node in a sorted linked list
Node *sorted_insert(Node *head, int &data) {
    Node *newNode = new Node(data);
    Node *curr = head;
    if(head == nullptr || head->data >= newNode->data) {
        Node* temp = curr;
        curr = newNode;
        newNode->next = temp;
        return newNode;
    }
    while((curr -> next) != nullptr &&(curr -> next -> data) < (newNode -> data)) {
        curr = curr -> next;
    }
    Node *temp = curr -> next;
    curr -> next = newNode;
    newNode -> next = temp;
    return head;
}

int main() {
    Node *head = take_input();
    int data;
    cin>>data;
    head = sorted_insert(head, data);
    print(head);
    cout<<endl;
    delete head;
    return 0;
}