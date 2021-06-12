#include<iostream>
using namespace std;

// Creating a node data type
template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        next=nullptr;
    }
};

template <typename T>
class Deque {
    Node<T> *front;
    Node<T> *rear;
    int size;
public:
    Deque() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // this function returns the size of deque
    int getSize() {
        return size;
    }

    // this functions checks whether deque is empty or not
    bool isEmpty() {
        return (size==0);
    }

    // this function inserts node from front
    void insertFront(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(front == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            newNode->next = front;
            front = newNode;
        }
        size++;
    }

    // this function inserts node from rear
    void insertRear(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(rear == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = rear->next;
        }
    }

    // this function returns front element
    T getFront() {
        if(isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return 0;
        }
        return front->data;
    }

    // this function returns rear element
    T getRear() {
        if(isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return 0;
        }
        return rear->data;
    }

    // this function deletes front element
    void deleteFront() {
        if(isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return ;
        }
        Node<T> *temp = front;
        front = front->next;
        delete (temp);
    }

    // this function deletes rear element
    void deleteRear() {
        if(isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return ;
        }
        Node<T> *temp = rear;
        rear = front;
        while(rear->next != temp) { // You can use another node for node before rear node for O(1) time complexity
            rear = rear->next;
        }
        delete (temp);
    }
};

int main() {
    Deque<int> d1;
    d1.insertFront(10);   
    d1.insertFront(20);
    d1.insertRear(30);
    d1.insertRear(40);
    d1.deleteFront();
    d1.deleteFront();
    d1.deleteRear();
    cout<<d1.getFront()<<endl;
    cout<<d1.getRear()<<endl;
    return 0;
}