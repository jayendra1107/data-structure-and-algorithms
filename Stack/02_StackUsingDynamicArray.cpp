// In this program I have taken basic approach by creating dynamic arrays you can even use templates at this place

#include<iostream>
using namespace std;

class StackUsingArray {
    int *data;
    int capacity;
    int nextIndex;
public:

    StackUsingArray() {
        data = new int[4];  // By default we are taking array size as 4
        capacity = 4;
        nextIndex = 0;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return (nextIndex == 0);
    }

    void push(int element) {
        if(nextIndex == capacity) {
            int *newData = new int[2*capacity]; // Here we have created an array double to the size of it
            for(int i=0; i<capacity; i++) { // Assigning values of previous array to new array
                newData[i] = data[i];
            }
            capacity *= 2;
            int *temp = data;   // Storing data array to temp
            data = newData; // to point data to new array which is double its size
            delete [] temp; // Deleting temp array
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop() {
        if(isEmpty()) {
            cout<<"Stack is empty ";
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top() {
        if(isEmpty()) {
            cout<<"Stack is empty ";
            return 0;
        }
        return data[nextIndex-1];
    }
};

int main() {
    StackUsingArray s;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.size()<<endl;

}