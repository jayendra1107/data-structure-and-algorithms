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
    if(head->next == head) {
        return nullptr;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next= temp->next;
    delete(temp);
    return head;
}

// Deleting ith node of circular linked list
Node *delete_ith_node(Node *head, int &i) {
    if(head == nullptr) {
        return nullptr;
    }
    if(i==0) {
        return deleteHead(head);
    }
    Node *curr = head;
    for(int it=1; it<i; it++) {
        if(curr->next == head){
            return head;
        }
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete (temp);
    return head;
}

int main() {
    Node *head = take_input();
    int i;
    cin>>i;
    head = delete_ith_node(head, i);
    print(head);
    cout<<endl;
}