#include<iostream>
#include<stack>     // Importing stack library
using namespace std;

int main() {
    stack<int> s;
    // cout<<s.top()<<endl;     // This line will give you a segmentation fault. So it is better to handle it using s.empty().
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl;
    // s.pop();     // This line will give you a segmentation fault. So it is better to handle it using s.empty().
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.top()<<endl;
    s.pop();    // This is a void type in stack library unlike T type as we used in out previous programs
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}