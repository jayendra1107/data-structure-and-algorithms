#include<iostream>
#include<vector>
using namespace std;

// Creating a tree node data type
template <typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode<T>*> children;  // A vector array for holding children of parent node
    TreeNode(T data) {
        this->data = data;
    }
    ~TreeNode() {
        for(int i=0; i<children.size(); i++) {
            delete children[i]; 
        }
    }
};

void print(TreeNode<int>* root) {

    // Handling a corner case when root is nullptr
    if(root == nullptr) {
        return;
    }

    cout<< root->data << " : ";
    // Printing all the children of root node
    for(int i=0; i<root->children.size(); i++) {
        cout<< root->children[i]->data <<" ";
    }
    cout<<endl;

    for(int i=0; i<root->children.size(); i++) {
        print(root->children[i]);   // recursively printing elements of every child
    }

}

int main() {
    TreeNode<int> *root = new TreeNode<int>(1);     // Creating a root node
    TreeNode<int> *node1 = new TreeNode<int>(2);    // Creating 1st child
    TreeNode<int> *node2 = new TreeNode<int>(3);    // Creating 2nd child
    root->children.push_back(node1);    // Assigning child1 to root node as parent
    root->children.push_back(node2);    // Assigning child2 to root node as parent
    print(root);    // Printing Tree
    return 0;
}
