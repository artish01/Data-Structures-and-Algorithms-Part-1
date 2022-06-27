#include <iostream>
#include <queue>
using namespace std;
template <typename T>

class Binary_Tree
{
public:
    T data;
    Binary_Tree *left;
    Binary_Tree *right;

    Binary_Tree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~Binary_Tree()
    {
        delete left;
        delete right;
    }
};

Binary_Tree<int> *take()
{
    int rootdata;
    cout << "Enter root data ";
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }

    Binary_Tree<int> *root = new Binary_Tree<int>(rootdata);
    queue<Binary_Tree<int> *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        Binary_Tree<int> *front = pendingnodes.front();
        pendingnodes.pop();

        int leftchild;
        cout << "Enter left child of " << front->data << endl;
        cin >> leftchild;
        if (leftchild != -1)
        {

            Binary_Tree<int> *child = new Binary_Tree<int>(leftchild);
            pendingnodes.push(child);
            front->left = child;
        }

        int rightchild;
        cout << "Enter right child of " << front->data << endl;
        cin >> rightchild;

        if (rightchild != -1)
        {

            Binary_Tree<int> *child = new Binary_Tree<int>(rightchild);
            pendingnodes.push(child);
            front->right = child;
        }
    }
    return root;
}

void print(Binary_Tree<int> *root)
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

void print_level(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Binary_Tree<int> *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        Binary_Tree<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << front->data << " : ";

        if (front->left)
        {
            pendingnodes.push(front->left);
            cout << "L" << front->left->data << ",";
        }
        if (front->right)
        {
            pendingnodes.push(front->right);
            cout << "R" << front->right->data << ",";
        }
        cout << endl;
    }
}

Binary_Tree<int> *Treehelp(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int data = pre[preS];
    int rootindex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == data)
        {
            rootindex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootindex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = rootindex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    Binary_Tree<int> *root = new Binary_Tree<int>(data);
    root->left = Treehelp(in, pre, linS, linE, lpreS, lpreE);
    root->right = Treehelp(in, pre, rinS, rinE, rpreS, rpreE);
    return root;
}

Binary_Tree<int> *inpre(int *in, int *pre, int size)
{
    return Treehelp(in, pre, 0, size - 1, 0, size - 1);
}

int main()
{
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};

    Binary_Tree<int> *Build = inpre(in, pre, 9);

    // Binary_Tree<int> *root = take();
    print_level(Build);

    return 0;
}

