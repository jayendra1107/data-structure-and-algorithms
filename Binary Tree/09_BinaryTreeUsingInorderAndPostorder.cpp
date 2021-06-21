#include<iostream>
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

BinaryTreeNode<int>* buildTreeHelper(int* in, int* post, int inS, int inE, int postS, int postE) {
    if(inS > inE) {
        return nullptr;
    }
    int rootData = post[postE];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    int rootIndex = -1;
    for(int i=inS; i<=inE; i++) {
        if(in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;

    root->left = buildTreeHelper(in, post, lInS, lInE, lPostS, lPostE);
    root->right = buildTreeHelper(in, post, rInS, rInE, rPostS, rPostE);

    return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* post, int &size) {
    return buildTreeHelper(in, post, 0, size-1, 0, size-1);
}

int main() {
    int size;
    cin >> size;
    int *in = new int[size];
    int *post = new int[size];
    for(int i=0; i<size; i++) {
        cin >> in[i];
    }
    for(int i=0; i<size; i++) {
        cin >> post[i];
    }
    BinaryTreeNode<int> *root = buildTree(in, post, size);
    print(root);
    return 0;
}