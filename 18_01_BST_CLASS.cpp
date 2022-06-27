#include <iostream>
using namespace std;
template <typename T>

class Binarytree
{
public:
    T data;
    Binarytree<T> *left;
    Binarytree<T> *right;

    Binarytree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~Binarytree()
    {
        delete left;
        delete right;
    }
};

class BST
{
    Binarytree<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    Binarytree<int> *deleteData(int data, Binarytree<int> *node)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else if (data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                Binarytree<int> *temp = node->right;
                node->right = NULL;
                delete node;

                return temp;
            }
            else if (node->right == NULL)
            {
                Binarytree<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                Binarytree<int> *rightmin = node->right;
                while (rightmin->left != NULL)
                {
                    rightmin = rightmin->left;
                }
                int minData = rightmin->data;
                node->data = minData;
                node->right = deleteData(minData, node->right);
                return node;
            }
        }
    }

public:
    void deleteData(int data)
    {

        this->root = deleteData(data, root); // main head root h i guess haar baar jb bi operation hoga tb ye change hogi
    }                                        // accordingly ki root same h ya diffrent like what if head is needed to be replaced

private:
    Binarytree<int> *insertData(int data, Binarytree<int> *root)
    {

        if (root == NULL)
        {

            Binarytree<int> *newnode = new Binarytree<int>(data);
            return newnode;
        }
        if (data < root->data)
        {
            root->left = insertData(data, root->left);
        }
        else if (data > root->data)
        {
            root->right = insertData(data, root->right);
        }

        return root;
    }

public:
    void insertData(int data)
    {
        this->root = insertData(data, root);
    }

private:
    bool hasData(int data, Binarytree<int> *root)
    {

        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }

        if (data < root->data)
        {
            return hasData(data, root->left);
        }

        else
        {

            return hasData(data, root->right);
        }
    }
    void pre(Binarytree<int> *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << " ";
        pre(root->left);
        pre(root->right);
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
    void print()
    {

        pre(root);
    }
};

int main()
{
    BST b;

    b.insertData(100);
    b.insertData(50);
    b.insertData(130);
    b.insertData(120);

    b.print();

    return 0;
}