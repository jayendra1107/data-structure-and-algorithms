// Program to delete a node at ith position

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

// Deletion in Linked List Using Iteration
Node *delete_node(Node *head, int &i) {
    int count = 0;
    Node *curr = head;

    if(i==0 && curr != nullptr) {
        head = curr -> next;
    }

    while(count < i-1 && curr != nullptr) {
        count++;
        curr = curr -> next;
    }
    if(curr != nullptr) {
        curr -> next = curr -> next -> next;
    }
    return head;
}

// Deletion in Linked List Using Recursion
Node *delete_using_recursion(Node *head, int i) {
    if (head == nullptr) {
        return head;
    }
    else if(i==0) {
        head = head->next;
        return head;
    }
    else if (i == 1) {
        head -> next = head -> next -> next;
        return head;
    }
    else {
        head -> next = delete_using_recursion(head->next, i-1);
        return head;
    }
}

int main() {
    Node *head = take_input();
    int i;
    cin>>i;
    head = delete_using_recursion(head, i);
    print(head);
    cout<<endl;
    delete head;
    return 0;
}