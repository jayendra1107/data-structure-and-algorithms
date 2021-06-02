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
    if(head != nullptr){
        tail->next = head;
    }
    return head;
}

// Printing circular linked list using for loop
void print_method_1(Node *head) {
    if(head == nullptr) return;
    cout<< head->data <<" ";
    for(Node* i = head->next; i != head; i = i->next) {
        cout<< i->data <<" ";
    }
}

// Printing circular linked list using do while loop
void print_method_2(Node *head) {
    if(head==nullptr) return;
    Node *p = head;
    do {
        cout<< p->data <<" ";
        p = p->next;
    } while(p!=head);
}

int main() {
    Node *head = take_input();
    print_method_1(head);
    cout<<endl;
    print_method_2(head);
    cout<<endl;
    return 0;
}
