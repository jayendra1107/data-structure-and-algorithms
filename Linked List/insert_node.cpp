// Program to insert a node

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

// Insertion in Linked List Using Iteration
Node *insert(Node *head, int &i, int &data) {
    Node *newNode = new Node(data);
    int count = 0;
    Node *curr = head;

    if(i==0) {
        newNode -> next = curr;
        return newNode;
    }

    while(count < i-1 && curr!= nullptr) {
        count++;
        curr = curr -> next;
    }

    if(curr != nullptr) {
        Node *temp = curr -> next;
        curr -> next = newNode;
        newNode -> next = temp;
    }
    return head;
}

// Insertion in Linked List Using Recursion
Node *insert_using_recursion(Node *head, int i, int &data){
    Node *curr = head;
    if (i==0) {
        Node *newNode = new Node(data);
        newNode -> next = curr;
        return newNode;
    }
    else if(head == nullptr) {
        return head;
    }
    else if(i==1) {
        Node *newNode = new Node(data);
        Node *temp = head -> next;
        head -> next = newNode;
        newNode -> next = temp;
        return head;
    }
    else {
        head -> next = insert_using_recursion(head -> next, i-1, data);
        return head;
    }
}

int main() {
    Node *head = take_input();
    int i, data;
    cin>>i>>data;
    head = insert_using_recursion(head, i, data);
    print(head);
    cout<<endl;
    delete head;
    return 0;
}