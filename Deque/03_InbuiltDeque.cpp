#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> d;
    d.push_front(10);
    d.push_front(20);
    d.push_back(30);
    d.push_back(40);
    d.pop_front();
    d.pop_back();
    cout<<d.size()<<endl;
    cout<<d.empty()<<endl;
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
}