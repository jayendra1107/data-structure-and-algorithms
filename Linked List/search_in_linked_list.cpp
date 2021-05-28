// Program to search element in linked list

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
    while(data != -1) {         // Take input until -1 is encountered
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

// Iterative Solution
int search(Node *head, int &x) {
    Node *curr = head;
    int pos = 1;
    while(curr != nullptr) {
        if(curr -> data == x)
            return pos;
        pos++;
        curr = curr -> next;
    }
    return -1;
}

// Recursive Solution
int search_recursive(Node *head, int x) {
    if(head == nullptr)
        return -1;
    if(head -> data == x)
        return 1;
    else {
        int res = search_recursive(head -> next, x);
        if(res == -1)
            return -1;
        else 
            return res+1;
    }
}

int main() {
    cout<< "Enter elements of Linked List :-\n";
    Node *head = take_input();
    cout<< "Enter element to be searched :-\n";
    int num;
    cin>>num;
    cout<<"Element found at "<<search_recursive(head, num)<<"\n";
    return 0;
}