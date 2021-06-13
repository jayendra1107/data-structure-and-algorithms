#include<iostream>
#include<vector>
#include<queue>
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

// Printing Tree
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

// Taking input of tree
TreeNode<int>* takeInput() {
    int rootData;
    cout<<"Enter root element : ";
    cin>>rootData;  // Taking input of root data

    TreeNode<int> *root = new TreeNode<int>(rootData);  // Creating root node of the tree
    queue<TreeNode<int>*> pendingNodes; // Queue to take input of pending nodes
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout << "Enter no. of children of " << front->data <<" : ";
        cin>>n;
        for(int i=0; i<n; i++) {
            int childData;
            cout << "Enter child " << i+1 << " : ";
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);    // Creating each child node
            front->children.push_back(child);    // Connecting child node to its parent node
            pendingNodes.push(child);   // pushing child in queue for input of its children
        }
    }
    return root;
}

int main() {
    TreeNode<int> *root = takeInput();
    print(root);
    return 0;
}