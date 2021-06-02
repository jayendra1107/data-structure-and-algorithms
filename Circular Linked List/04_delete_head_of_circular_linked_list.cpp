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

// Deleting head node of circular linked list in O(1)
Node *deleteHead(Node *head) {
    if(head==nullptr || head->next == head) {
        return nullptr;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next= temp->next;
    delete(temp);
    return head;
}

int main() {
    Node *head = take_input();
    head = deleteHead(head);
    print(head);
    cout<<endl;
}