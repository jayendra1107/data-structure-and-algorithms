#include<iostream>
using namespace std;

// Creating a node data type to handle T type of data
template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

// Creating queue class
template <typename T>
class Queue {
    Node<T> *head;  // for holding head element
    Node<T> *tail;  // for holding tail elmen
    int length;
public:
    Queue() {
        head = nullptr; // by default head will be nullptr
        curr = nullptr;
        length = 0; // default length of the linked list is 0
    }

    // This function returns the size of the queue
    int size() {
        return length;
    }

    // This function checks whether the linked list is empty or not
    bool isEmpty() {
        return (length == 0);
    }

    // This function inserts element in a linked list
    void enqueue(T element) {
        Node<T> *newNode = new Node<T>(element);    // Creating a new node
        if(head == nullptr) {   // If head is nullptr we have to assign newNode to it and tail as well
            head = newNode;
            tail = head;
        }
        else {  // Else we will add newnode at the end of the linked list
            tail->next = newNode;
            tail = tail->next;
        }
        
        length++;
    }

    // This function returns front element of the queue
    T front() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return head->data;
    }

    // This element removes the first element from the queue
    T dequeue() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T res = head->data;
        Node<T> *temp = head;
        head = head->next;  // head will point to next node as it will hold the front element in the queue
        delete (temp);
        length--;
        return res;
    }

};

int main() {
    Queue<char> q1;
    cout<<q1.size()<<endl;
    cout<<q1.isEmpty()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.front()<<endl;
    q1.enqueue('A');
    q1.enqueue('B');
    q1.enqueue('C');
    q1.enqueue('D');
    q1.enqueue('E');
    q1.enqueue('F');
    cout<<q1.size()<<endl;
    cout<<q1.isEmpty()<<endl;
    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.front()<<endl;
    return 0;
}
