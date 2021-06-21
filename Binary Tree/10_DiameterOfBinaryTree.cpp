// Diameter of a binary tree is called as maximum distance b/w two nodes 
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cout << "Enter root element : ";
    cin >> rootData;
    if(rootData == -1) {
        return nullptr;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cout << "Enter left child of " << front->data << " : ";
        cin >> leftChildData;
        if(leftChildData != -1) {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftChildData);
            front->left = left;
            pendingNodes.push(left); 
        }
        int rightChildData;
        cout << "Enter right child of " << front->data << " : ";
        cin >> rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightChildData);
            front->right = right;
            pendingNodes.push(right); 
        }
    }
    return root;
}

int max(int &a, int &b) {
    return (a>b?a:b);
}

pair<int, int> diameter(BinaryTreeNode<int>* root) {
    if(root == nullptr) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);
    pair<int, int> p;
    p.first = 1 + max(left.first, right.first);
    p.second = max( left.first+right.first, max(left.second, right.second) );
    return p;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> d = diameter(root);
    cout << d.second << endl;
    return 0;
}