#include <iostream>
using namespace std;

// Creating a Node data type for linked list
class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Taking Input
// This function takes input till -1
Node *take_input() {
    Node *head = nullptr;
    Node *tail = head;
    int data;
    cin>>data;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    if(head != nullptr) {
        tail->next = head;
    }
    return head;
}

// Printing circular linked list
void print(Node *head) {
    if(head==nullptr) return;
    Node *p = head;
    do {
        cout<< p->data <<" ";
        p = p->next;
    } while(p!=head);
}

// Inserting at the end of circular linked list in O(1)
Node* insertEnd(Node *head, int data) {
    if(head == nullptr) {
        Node *newNode = new Node(data);
        newNode->next = newNode;
        return newNode;
    }
    Node *newNode = new Node(head->data);
    if(head == nullptr)
        return newNode;
    newNode->next = head->next;
    head->data = data;
    head->next = newNode;
    return newNode;
}

int main() {
    Node *head = take_input();
    int data;
    cin>>data;
    head = insertEnd(head, data);
    print(head);
    cout<<endl;
    return 0;
}