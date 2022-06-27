#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
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

// Binary_Tree<int> *takelevel_wise()
// {
//     cout << "Enter root data " << endl;
//     int rootdata;
//     cin >> rootdata;
//     if (rootdata == -1)
//     {
//         return NULL;
//     }
//     Binary_Tree<int> *root = new Binary_Tree<int>(rootdata);
//     queue<Binary_Tree<int> *> pendingnodes;
//     pendingnodes.push(root);

//     while (pendingnodes.size() != 0)

//     {
//         Binary_Tree<int> *front = pendingnodes.front();
//         pendingnodes.pop();

//         int leftchild;
//         cout << "Enter left child data of " << front->data << endl;
//         cin >> leftchild;
//         if (leftchild != -1)
//         {
//             Binary_Tree<int> *child = new Binary_Tree<int>(rootdata);
//             front->left = child;
//             pendingnodes.push(child);
//         }

//         int rightchild;
//         cout << "Enter right child data of " << front->data << endl;
//         cin >> rightchild;
//         if (rightchild != -1)
//         {
//             Binary_Tree<int> *child = new Binary_Tree<int>(rootdata);
//             front->right = child;
//             pendingnodes.push(child);
//         }

//     }
//     return root;
// }

Binary_Tree<int> *takelevel_wise()
{
    cout << "Enter root data ";
    int rootdata;
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
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftchild;
        if (leftchild != -1)
        {
            Binary_Tree<int> *child = new Binary_Tree<int>(leftchild);
            front->left = child;
            pendingnodes.push(child);
        }

        int rightchild;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightchild;
        if (rightchild != -1)
        {
            Binary_Tree<int> *child = new Binary_Tree<int>(rightchild);
            front->right = child;
            pendingnodes.push(child);
        }
    }
    return root;
}

// count nodes
int count(Binary_Tree<int> *root)
{
    int ans = 1;
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

// find a node

bool find_node(Binary_Tree<int> *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (find_node(root->left, key))
    {
        return true;
    }
    return find_node(root->right, key);
}

// find height

int find_height(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = find_height(root->left);
    int right = find_height(root->right);

    return max(left, right) + 1;
}

// preorder print

void pre_order(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left)
    {
        cout << "L " << root->left->data;
    }
    if (root->right)
    {
        cout << " R " << root->right->data;
    }
    cout << endl;
    pre_order(root->left);
    pre_order(root->right);
}

// post_order

void post_order(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

// Inorder

void In_order(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    In_order(root->left);
    cout << root->data;
    In_order(root->right);
}

// constrcut tree from inorder and preorder
Binary_Tree<int> *Buildhelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootdata = pre[preS];
    int rootindex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootdata)
        {
            rootindex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootindex - 1;
    int lpreS = preS + 1;
    int lpreE = lpreS - linS + linE;
    int rinS = rootindex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    Binary_Tree<int> *root = new Binary_Tree<int>(rootdata);
    root->left = Buildhelper(in, pre, linS, linE, lpreS, lpreE);
    root->right = Buildhelper(in, pre, rinS, rinE, rpreS, rpreE);

    return root;
}

Binary_Tree<int> *Buildtree(int *in, int *pre, int size)
{
    return Buildhelper(in, pre, 0, size - 1, 0, size - 1);
}

int height(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// Diameter of a tree

int Diamter(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = Diamter(root->left);
    int option3 = Diamter(root->right);
    return max(option1, max(option2, option3));
}

// is balanced

// also done from striver

bool isBalanced(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int left = height(root->left);
    int right = height(root->right);
    if ((abs(left - right) == 0 || abs(left - right) == 1) && isBalanced(root->left) && isBalanced(root->right))
    {
        return 1; // is  balanced
    }
    return 0; // is not balanced
}

// level order traveresal

void printlevel(Binary_Tree<int> *root)
{
    queue<Binary_Tree<int> *> pending;

    pending.push(root);
    pending.push(NULL);

    while (pending.size() != 0)
    {
        Binary_Tree<int> *fr = pending.front();
        pending.pop();

        if (fr == NULL)
        {
            if (pending.size() == 0)
            {
                break;
            }
            else
            {
                cout << endl;
                pending.push(NULL);
            }
        }
        else
        {
            cout << fr->data << ",";
            if (root->left != NULL)
            {
                pending.push(fr->left);
            }
            if (root->right != NULL)
            {
                pending.push(fr->right);
            }
        }
    }
}
// delete all leaf nodes

Binary_Tree<int> *leafDelete(Binary_Tree<int> *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Else recursively delete in left and right
    // subtrees.
    root->left = leafDelete(root->left);
    root->right = leafDelete(root->right);

    return root;
}

// zig zag traversal
//striver
vector<vector<int>> zigzag(Binary_Tree<int> *root)
{
    vector<vector<int>> store;
    if (root == NULL)
    {
        return store;
    }
    queue<Binary_Tree<int> *> pending;
    pending.push(root);
    bool lefttoright = true;
    while (pending.size() != 0)
    {
        int size = pending.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            Binary_Tree<int> *node = pending.front();
            pending.pop();
            int index = (lefttoright) ? i : (size - i - 1);
            row[index] = node->data;
            if (node->left)
            {
                pending.push(node->left);
            }
            if (node->right)
            {
                pending.push(node->right);
            }
        }
        lefttoright = !lefttoright;
        store.push_back(row);
    }
    return store;
}

int main()
{
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    // Binary_Tree<int> *take = Buildtree(in, pre, 9);

    Binary_Tree<int> *take = takelevel_wise();
    vector<vector<int>> del = zigzag(take);
    for(int i =0; i<del.size(); i++)
    {
        for (int j = 0; j < del[i].size(); j++)
        {
            cout << del[i][j] << " ";
        }
        cout << endl;
    }

    // Binary_Tree<int> *takeleaf = leafDelete(take);
    // pre_order(takeleaf);

    // cout<<isBalanced (take);
    // cout << find_height(take);
    // post_order(take);

    // if(find_node(take,12))
    // {
    //     cout<<"True";
    // }
    // else{
    //     cout<<"false";
    // }

    // pre_order(take);

    return 0;
}