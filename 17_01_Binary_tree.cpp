#include <iostream>
using namespace std;
template <typename T>

class Binary_TreeNode
{
public:
    T data;
    Binary_TreeNode *left;
    Binary_TreeNode *right;

    Binary_TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~Binary_TreeNode()
    {
        delete left;
        delete right;
    }
};

Binary_TreeNode<int> *take() // return type is of class
{
    int rootdata;
    cout << "Enter rootdata ";
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    Binary_TreeNode<int> *root = new Binary_TreeNode<int>(rootdata);

    Binary_TreeNode<int> *leftchild = take();
    Binary_TreeNode<int> *rightchild = take();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}

void print_Tree(Binary_TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";

    if (root->left)
    {
        cout << " L " << root->left->data;
    }
    if (root->right)
    {
        cout << " R " << root->right->data;
    }
    cout << endl;
    print_Tree(root->left);
    print_Tree(root->right);
}

int main()
{

    Binary_TreeNode<int> *root = new Binary_TreeNode<int>(12); // object create
    Binary_TreeNode<int> *leftc = new Binary_TreeNode<int>(1);
    Binary_TreeNode<int> *rightc = new Binary_TreeNode<int>(62);
    root->left = leftc;
    root->right = rightc;
    print_Tree(root);

    return 0;
}