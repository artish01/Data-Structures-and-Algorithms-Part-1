#include <iostream>
#include <queue>
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

Binary_TreeNode<int> *take_levelwise()
{
    cout << "Enter root data ";
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }

    Binary_TreeNode<int> *root = new Binary_TreeNode<int>(rootdata);
    queue<Binary_TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        Binary_TreeNode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        int leftchild;
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftchild;
        if (leftchild != -1)
        {
            Binary_TreeNode<int> *child = new Binary_TreeNode<int>(leftchild);
            front->left = child;
            pendingnodes.push(child);
        }

        int rightchild;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightchild;
        if (rightchild != -1)
        {
            Binary_TreeNode<int> *child = new Binary_TreeNode<int>(rightchild);
            front->right = child;
            pendingnodes.push(child);
        }
    }
    return root;
}

void print(Binary_TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left)
    {
        cout << root->left->data << ",";
    }
    if (root->right)
    {
        cout << root->right->data << ",";
    }
    cout << endl;

    print(root->left);
    print(root->right);
}

void print_levelwise(Binary_TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Binary_TreeNode<int> *> pending;
    pending.push(root);
    while (pending.size() != 0)
    {
        Binary_TreeNode<int> *front = pending.front();
        pending.pop();
        cout << front->data << " : ";

        if (front->left)
        {
            pending.push(front->left);
            cout << " L " << front->left->data << ",";
        }

        if (front->right)
        {
            pending.push(front->right);
            cout << " R " << front->right->data << ",";
        }
        cout << endl;
    }
}

int main()
{
    Binary_TreeNode<int> *take = take_levelwise();
    print_levelwise(take);

    return 0;
}