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

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
    if(inS>inE) {
        return nullptr;
    }
    
    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i=inS; i<=inE; i++) {
        if(in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;   // Since size will be same so, lInE - lInS = lPreE - lPreS => lPreE = lInE - lInS + lPreS
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int &size) {
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);
}

int main() {
    int size;
    cin >> size;
    int *in = new int[size];
    int *pre = new int[size];
    for(int i=0; i<size; i++) {
        cin >> in[i];
    }
    for(int i=0; i<size; i++) {
        cin >> pre[i];
    }

    BinaryTreeNode<int>* root = buildTree(in, pre, size);
    print(root);
    return 0;
}