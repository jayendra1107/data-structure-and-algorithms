#include<iostream>
using namespace std;

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

template <typename T>
class Queue {
    Node<T> *head;
    Node<T> *curr;
    int length;
public:
    Queue() {
        head = nullptr;
        curr = nullptr;
        length = 0;
    }

    int size() {
        return length;
    }

    bool isEmpty() {
        return (length == 0);
    }

    void enqueue(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(head == nullptr) {
            head = newNode;
            curr = head;
            length++;
            return ;
        }
        curr->next = newNode;
        curr = curr->next;
        length++;
    }

    T front() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return head->data;
    }

    T dequeue() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T res = head->data;
        Node<T> *temp = head;
        head = head->next;
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