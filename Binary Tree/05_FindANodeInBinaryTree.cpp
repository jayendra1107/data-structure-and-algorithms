#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
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

bool find(BinaryTreeNode<int> *root, int &element) {
    if(root == nullptr) {
        return false;
    }
    if(root->data == element) {
        return true;
    }
    return (find(root->left, element) | find(root->right, element));
}

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

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int element;
    cout << "Enter the element you want to search : ";
    cin >> element;
    cout << find(root, element) << endl;
    return 0;
}