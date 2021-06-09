#include<iostream>
using namespace std;

template <typename T>   // Template for assigning data type to the class elements
class Queue {
    T *data;    // data pointer of T type
    int size;
    int firstIndex;
    int nextIndex;
    int capacity;
public:
    Queue(int s) {
        this->capacity = s; // assigning capacity to s
        size=0;
        data = new T[s];    // creating an array of size s
        firstIndex = -1;    // by default the first index is -1
        nextIndex = 0;
    }

    // this function returns size of the queue
    int getSize() {
        return size;
    }

    // this function checks whether the queue is empty or not
    bool isEmpty() {
        return (size==0) ;
    }

    // this function inserts element in queue
    void enqueue(T element) {
        if(size==capacity) {
            cout<<"Queue full"<<endl;   // If queue is full no element can be inserted
            return ;
        }
        if(firstIndex == -1) {          // If the first index is -1 it should move to 0th position
            firstIndex = 0;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1) % capacity;   // this line assigns the next index in a circular manner of the array
        size++;
    }

    // this function returns the front element of the queue
    T front() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    // This function removes front element from the queue
    T dequeue() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T temp = data[firstIndex];
        firstIndex = (firstIndex+1) % capacity; // This line assigns the first index in circular manner of the array
        size--;
        if(size==0) {   // if queue becomes empty we change the values of indexes to the default values
            firstIndex = -1;
            nextIndex = 0;
        }
        return temp;
    }
};

int main() {
    Queue<char> q1(5);
    cout<<q1.getSize()<<endl;
    cout<<q1.isEmpty()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.front()<<endl;
    q1.enqueue('A');
    q1.enqueue('B');
    q1.enqueue('C');
    q1.enqueue('D');
    q1.enqueue('E');
    q1.enqueue('F');
    cout<<q1.getSize()<<endl;
    cout<<q1.isEmpty()<<endl;
    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.front()<<endl;
    return 0;
}
