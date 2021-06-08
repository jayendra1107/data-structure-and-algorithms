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

template <typename T>   // For every class we need to define its template.
class Stack{
    Node<T> *head;
    int length;
public:

    Stack() {
        head = nullptr; // By default head will be nullptr.
        length=0;   // By default length will be zero.
    }

    // This function returns the size of linked list.
    int size() {
        return length;
    }

    // This function checks whether the linked list is empty or not.
    bool isEmpty() {
        return (length==0);
    }

    // This function creates a new node and assign its next to head and later mark itself as the head node.
    void push(T data){
        Node<T> *newNode = new Node<T>(data);   // Wherever we write node we have to specify the template type.
        newNode->next = head;
            head = newNode;
            length++;
    }
    
    // This function pops the head element and assign head to head->next.
    T pop() {
        if(isEmpty()) {
            cout<<"Stack is empty";
            return 0;
        }
        Node<T> *temp = head;
        T data = head->data;
        head = head->next;
        delete (temp);
        length--;
        return data;
    }

    // This function return head->data.
    T top() {
        if(isEmpty()) {
            cout<<"Stack is empty";
            return 0;
        }
        return head->data;
    }
};

int main() {
    Stack<char> s1; // Creating an object of stack which handles char values, you can even handle multiple type of values using templates.
    cout<<s1.isEmpty()<<endl;
    cout<<s1.size()<<endl;
    s1.push('A');
    s1.push('B');
    s1.push('C');
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    return 0;
}