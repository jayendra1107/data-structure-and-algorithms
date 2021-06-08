// In this program we will be using templates to handle data of different types in our stack

#include<iostream>
using namespace std;

template <typename T>   // Creating a template of T type, T will be assigned later at the time of creation of object
class StackUsingArray {
    T *data;    // Creating pointer of T type
    int capacity;
    int nextIndex;
public:

    StackUsingArray() {
        data = new T[4];
        capacity = 4;
        nextIndex = 0;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return (nextIndex == 0);
    }

    void push(T element) {  // Everywhere we have used primitive data type in previous program we will replace it with T
        if(nextIndex == capacity) {
            T *newData = new T[2*capacity];
            for(int i=0; i<capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            T *temp = data;
            data = newData;
            delete [] temp;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop() {   // Even the return type will be of T type
        if(isEmpty()) {
            cout<<"Stack is empty ";
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top() {
        if(isEmpty()) {
            cout<<"Stack is empty ";
            return 0;
        }
        return data[nextIndex-1];
    }
};

int main() {
    StackUsingArray<char> s;    // Here we have assigned T type as char type, We can even use primitive or user-defined data types
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    return 0;

}