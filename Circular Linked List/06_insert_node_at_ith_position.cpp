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

// Inserting a node at ith position in a circular linked list
void insertAtPosition(Node *head, int pos, int data)
{
   if(head == NULL && pos==0) {
       head = new Node(data);
       head->next = head;
   }
   if(pos==0){
       Node* newNode = new Node(head->data);
       newNode->next = head->next;
       head->next = newNode;
       head->data = data;
       return;
   }
   Node *curr = head;
   for(int i=1; i<pos; i++) {
        curr = curr->next;
        if(curr== head)
            return;
   }
   cout<<curr->data<<endl;
   Node *newNode = new Node(data);
   newNode->next = curr->next;
   curr->next = newNode;
}

int main() {
    Node *head = take_input();
    int pos;
    cin>>pos;
    int data;
    cin>>data;
    insertAtPosition(head, pos, data);
    print(head);
    cout<<endl;
    return 0;
}

