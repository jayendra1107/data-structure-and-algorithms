#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    cout<<q.empty()<<endl;
    cout<<q.size()<<endl;
    // cout<<q.front()<<endl; This line will give segmentation fault
    // q.pop(); This line will give segmentation fault, So check whether queue is empty or not before performing such operations
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.size()<<endl;
    // You can use such loops to perform many applications of queue
    while(!q.empty()) {
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}