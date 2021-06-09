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
    Queue() {
        capacity = 4; // assuming initial capacity as 4
        size=0;
        data = new T[4];    // creating an array of size 4
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
        // If size  is equal to capacity this means our array is full and we have to increase the size of array
        if(size == capacity) {
            T *newData = new T[capacity*2]; // new array of 2x capacity
            int i=0;
            while(firstIndex<capacity) {    // Since firstIndex is stored in a circular manner we will copy elements from firstIndex till capacity to new array at first
                newData[i] = data[firstIndex];
                firstIndex++;
                i++;
            }
            nextIndex --;
            while(nextIndex != -1) { // Since nextIndex is also stored in circular manner we will copy element from nextIndex-1 to 0 in to that array, this will arrange our queue from 0 to capacity with 0 as firstIndex and capacity as nextIndex         
                newData[i] = data[nextIndex];
                i++;
            }
            nextIndex = capacity;   //nextIndex will be equal to capacity
            firstIndex = 0; // firstIndex will become 0
            capacity *=2;   // capacity will now be twice of its size  
            delete [] data; // delete the old array
            data = newData; // copy new array to data;
        }
        if (firstIndex == -1) {  // If the first index is -1 it should move to 0th position
            firstIndex = 0;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity; // this line assigns the nextIndex in a circular manner of the array
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

    // this function removes front element from the queue
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
    Queue<char> q1;
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