#include<iostream>
using namespace std;

// Creating stack data type using array
class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
public:

    // default constructor
    StackUsingArray(int capacity) {
        this->capacity = capacity;  // assigns capacity of the stack
        data = new int[capacity];   // creating array of size capacity
        nextIndex = 0;              // assigns default index value to 0
    }

    // current size of stack
    int size() {
        return nextIndex;
    }

    // check whether stack is empty or not
    bool isEmpty() {
        return (nextIndex==0);
    }

    // insert an element on the top of stack
    void push(int element) {

        // checks whether stack is full or not
        if(nextIndex == capacity) {
            cout<<"Stack is full"<<endl;
            return ;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // delete top-most element of the stack
    int pop() {

        // checks whether stack is empty or not
        if(isEmpty()) {
           cout<<"Stack is empty ";
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    // top-most element of the stack
    int top() {

        // checks whether stack is empty or not
        if(isEmpty()) {
            cout<<"Stack is empty ";
            return 0;
        }

        return data[nextIndex-1];
    }

};

int main() {
    StackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}
