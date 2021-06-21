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

void print(BinaryTreeNode<int> *root) {
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

void preOrder(BinaryTreeNode<int> *root) {
    if(root == nullptr) {
        return ;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root) {
    if(root == nullptr) {
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(BinaryTreeNode<int> *root) {
    if(root == nullptr) {
        return ;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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
    preOrder(root);     // node -> left ->right
    cout << endl;
    postOrder(root);    // left -> right -> node
    cout<< endl;
    inOrder(root);      // left -> node -> right
    cout<<endl;
    return 0;
}