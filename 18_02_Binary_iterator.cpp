#include <iostream>
#include <queue>
#include <stack>
using namespace std;
////   Striver question with concept of BST iterator 
template <typename T>
class Binary_Tree
{
public:
    T data; // T bcz we hav euse template and during the creation of data we dont about the type of T it is
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

class BSTiterstor
{
private:
    stack<Binary_Tree<int> *> in_order_stack;
    bool reverse = true;

public:
    BSTiterstor(Binary_Tree<int> *root, bool isreverse)
    {
        reverse = isreverse;
        pull_up(root);
    }

    bool hasnext()
    {
        return !in_order_stack.empty();
    }
    int next()
    {
        Binary_Tree<int> *temp = in_order_stack.top();
        in_order_stack.pop();
        if (!reverse)
        {
            pull_up(temp->right);
        }
        else
        {
            pull_up(temp->left);
        }
        return temp->data;
    }

private:
    void pull_up(Binary_Tree<int> *root)
    {
        while (root != NULL)
        {
            in_order_stack.push(root);
            if (reverse == true)
            {
                root = root->right;
            }
            else

            {

                root = root->left;
            }
        }
    }
};
// 100 50 150 30 70 120 180 -1 -1 60 90 -1 -1 -1 -1 -1 -1 -1 -1

bool find(Binary_Tree<int> *root, int k)
{
    if (!root)
    {
        return false;
    }

    BSTiterstor l(root, false);
    BSTiterstor r(root, true);

    int i = l.next();

    int j = r.next();

    while (i < j)
    {
        if (i + j == k)
        {
            return true;
        }
        else if (i + j < k)
        {
            i = l.next();
        }
        else
        {
            j = r.next();
        }
    }
    return false;
}

int main()
{
    Binary_Tree<int> *take1 = take();
    cout << find(take1, 100);

    return 0;
}