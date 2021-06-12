#include<iostream>
using namespace std;

template <typename T>
class Deque {
    T *data;
    int front;
    int rear;
    int size;
    int capacity;
public:
    Deque(int capacity) {
        this->capacity = capacity;
        data = new T[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // this function returns the size of deque
    int getSize() {
        return size;
    }

    // this function checks whether the deque is empty or not
    bool isEmpty() {
        return (size == 0);
    }

    // this function checks whether the deque is full or not
    bool isFull() {
        return (size == capacity);
    }

    // this function inserts element from the front
    void insertFront(T element) {
        if(isFull()) {
            cout<<"Deque is full"<<endl;
            return;
        }
        if(front == -1) {
            data[0] = element;
            front = 0;
            rear = 0;
        }
        else {
            front = (front+capacity-1) %capacity;
            data[front] = element;
        }
        
        size++;
    }

    // this function inserts element from rear
    void insertRear(T element) {
        if(isFull()) {
            cout<<"Deque is full"<<endl;
            return;
        }
        if(rear == -1) {
            data[0] = element;
            front = 0;
            rear = 0;
        }
        rear = (front+size)%capacity;
        data[rear] = element;
        size++;
    }

    // this function returns front element
    T getFront() {
        if(isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return 0;
        }
        return data[front];
    }

    // this function returns rear element
    T getRear() {
        if(isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return 0;
        }
        return data[rear];
    }

    // thus function deletes front element
    void deleteFront() {
        if(isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return ;
        }
        size--;
        front = (front+1)%capacity;
    }

    // this function deletes rear element
    void deleteRear() {
        if(isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return ;
        }
        size--;
        rear = (front+size-1)%capacity;
    }
};

int main() {
    Deque<int> d1(5);
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
