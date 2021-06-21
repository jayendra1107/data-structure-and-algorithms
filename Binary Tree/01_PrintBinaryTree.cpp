#include<iostream>
using namespace std;

template<typename T>
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
        delete (left);
        delete (right);
    }
};

void print (BinaryTreeNode<int> *root) {
    if(root == nullptr) {
        return ;
    }
    cout << root->data << " : ";
    if(root->left) {
        cout << "L" << root->left->data;
    }
    if(root->right) {
        cout << "R" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}

int main() {
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    print(root);
    return 0;
}
