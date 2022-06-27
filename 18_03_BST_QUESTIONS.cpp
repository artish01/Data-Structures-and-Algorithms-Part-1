#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>
using namespace std;

class NodeValue
{
public:
    int maxnode, minnode, maxsize;
    NodeValue(int minnode, int maxnode, int maxsize)
    {
        this->maxnode = maxnode;
        this->minnode = minnode;
        this->maxsize = maxsize;
    }
};
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>

class Binary_Tree
{
public:
    T data; // T bcz we haveuse template and during the creation of data we dont about the type of T it is
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

// print int range

void range(Binary_Tree<int> *root, int l, int h)
{
    if (root == NULL)
    {
        return;
    }

    if (l < root->data)
    {
        range(root->left, l, h);
    }

    if (l <= root->data && h >= root->data)
    {
        cout << root->data << " ";
    }
    if (h > root->data)
    {
        range(root->right, l, h);
    }
}

// Check BST
int maximum(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool Checkbst(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);

    bool output = (root->data > leftmax) && (root->data <= rightmin) && Checkbst(root->left) && Checkbst(root->right);
    return output;
}

// checkBST Better 2

class isBSTreturn
{
public:
    bool isBST;
    int minimum;
    int maximum;
};

isBSTreturn isBST2(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        isBSTreturn output;
        output.isBST = true;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        return output;
    }

    isBSTreturn leftOutput = isBST2(root->left);
    isBSTreturn rightOutput = isBST2(root->right);

    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    int minimum = min(root->data, max(leftOutput.minimum, rightOutput.minimum));

    bool isBSTval = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    isBSTreturn output;
    output.isBST = isBSTval;
    output.maximum = maximum;
    output.minimum = minimum;
    return output;
}

// Construct BST from a sorted array
// this is not is O(n) do it in O(n)

Binary_Tree<int> *AtoBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Binary_Tree<int> *root = new Binary_Tree<int>(arr[mid]);
    root->left = AtoBST(arr, start, mid - 1);
    root->right = AtoBST(arr, mid + 1, end);
    return root;
}
void pre(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

// BST TO LINKED LIST

Node<int> *BSTtoLL(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        Node<int> *newnode = new Node<int>(root->data);
        return newnode;
    }

    Node<int> *newnode = new Node<int>(root->data);
    Node<int> *leftoutput = BSTtoLL(root->left);
    Node<int> *rightoutput = BSTtoLL(root->right);
    cout << "ok";
    if (leftoutput != NULL)
    {
        Node<int> *temp = leftoutput;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    newnode->next = rightoutput;
    //  4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    if (leftoutput == NULL)
    {
        return newnode;
    }
    return leftoutput;
}

// ROOT TO NODE PATH

vector<int> *roottonode(Binary_Tree<int> *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        vector<int> *store = new vector<int>();
        store->push_back(root->data);
        return store;
    }
    vector<int> *left = roottonode(root->left, key);
    if (left != NULL)
    {
        left->push_back(root->data);
        return left;
    }
    vector<int> *right = roottonode(root->right, key);

    if (right != NULL)
    {
        right->push_back(root->data);
        return right;
    }
    else
    {
        return NULL;
    }
}

// INSERT DUPLICATE

Binary_Tree<int> *Insduplicate(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Binary_Tree<int> *duplicate = new Binary_Tree<int>(root->data);
    duplicate->left = root->left;
    root->left = duplicate;
    Insduplicate(duplicate->left);
    Insduplicate(root->right);
}

// PAIR SUM BINARY TREE

int k = 0;
void sum(Binary_Tree<int> *root, int *arr)
{
    if (root == NULL)
    {
        return;
    }
    arr[k++] = root->data;
    sum(root->left, arr);
    sum(root->right, arr);
}

void keysum(Binary_Tree<int> *root, int key)
{

    int arr[1000];
    sum(root, arr);
    sort(arr, arr + k);
    int x = 0;
    int y = k - 1;
    while (x < y)
    {
        if (arr[x] + arr[y] == key)
        {
            cout << arr[x] << " " << arr[y];
            cout << endl;
            x++;
            y--;
        }
        else if (arr[x] + arr[y] > key)
        {
            y--;
        }
        else if (arr[x] + arr[y] < key)
        {
            x++;
        }
    }
}

// LCA OF BST

int LCA_BST(Binary_Tree<int> *root, int val1, int val2)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == val1 || root->data == val2)
    {
        return root->data;
    }
    int left = LCA_BST(root->left, val1, val2);
    int right = LCA_BST(root->right, val1, val2);
    if (left == -1 && right == -1)
    {
        return -1;
    }

    if (left != -1 && right == -1)
    {
        return left;
    }
    if (left == -1 && right != -1)
    {
        return right;
    }

    else
        return root->data;
}

// LARGEST BST  uses its own class to set value of min,max and maxsize

NodeValue largestBSTSubtreeHelper(Binary_Tree<int> *root)
{
    if (root == NULL)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    NodeValue left = largestBSTSubtreeHelper(root->left);
    NodeValue right = largestBSTSubtreeHelper(root->right);

    if (root->data > left.maxnode && root->data < right.minnode)
    {
        return NodeValue(min(root->data, left.minnode), max(root->data, right.maxnode), left.maxsize + right.maxsize + 1);
    }
    else
    {
        return NodeValue(INT_MIN, INT_MAX, max(left.maxsize, right.maxsize));
    }
}
int largestBSTSubtree(Binary_Tree<int> *root)
{
    return largestBSTSubtreeHelper(root).maxsize;
}

// PATH SUM ROOT TO LEAAF NODE

void SUMRTOL_nodehelper(Binary_Tree<int> *root, int k, vector<int> store_nodes)
{
    if (root == NULL)
    {
        return;
    }
    store_nodes.push_back(root->data);
    k = k - root->data;
    if (!root->left && !root->right)
    {
        if (k == 0)
        {
            for (int i : store_nodes)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    SUMRTOL_nodehelper(root->left, k, store_nodes);
    SUMRTOL_nodehelper(root->right, k, store_nodes);
}

void SUMRTOL_node(Binary_Tree<int> *root, int k)
{
    vector<int> store_nodes;
    SUMRTOL_nodehelper(root, k, store_nodes);
}

// PRINT AT DISTANCE K

void collect_parent_helper(Binary_Tree<int> *root, unordered_map<Binary_Tree<int> *, Binary_Tree<int> *> &parent_track)
{

    queue<Binary_Tree<int> *> store;
    store.push(root);
    while (!store.empty())
    {
        Binary_Tree<int> *current = store.front();
        store.pop();

        if (current->left)
        {
            store.push(current->left);
            parent_track[current->left] = current;
        }

        if (current->right)
        {
            store.push(current->right);
            parent_track[current->right] = current;
        }
    }
}

vector<int> PrintatDk(Binary_Tree<int> *root, Binary_Tree<int> *target, int k)
{
    unordered_map<Binary_Tree<int> *, Binary_Tree<int> *> parent_track;
    collect_parent_helper(root, parent_track);

    unordered_map<Binary_Tree<int> *, bool> visited;
    queue<Binary_Tree<int> *> path_store;
    path_store.push(target);
    visited[target] = "true";
    int current_index = 0;
    while (!path_store.empty())
    {
        int size = path_store.size();
        if (current_index++ == k)
        {
            break;
        }

        for (int i = 0; i < size; i++)
        {
            Binary_Tree<int> *current = path_store.front();
            path_store.pop();

            if(current->left && !visited[current->left])
            {
                path_store.push(current->left);
                visited[current->left] = "true";

            }
            if(current->right && !visited[current->right])
            {
                path_store.push(current->right);
                visited[current->right] = "true";

            }

            if(parent_track[current] && visited[parent_track[current]])
            {
                path_store.push(parent_track[current]);
                visited[parent_track[current]] = "true";

            }
        }
    }

    vector<int> result;
    while(!path_store.size())
    {
        Binary_Tree<int>*current = path_store.front();
        path_store.pop();
        result.push_back(current->data);
    }
    return result;
}

int main()
{
    // Binary_Tree<int> *root = take();
    // cout << Checkbst(root);
    // cout << isBST2(root).isBST;
    // range(root, 30, 124);
    //
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // Binary_Tree<int> *BST = AtoBST(arr, 0, 6);
    // pre(BST);
    Binary_Tree<int> *take1 = take();

    // cout << largestBSTSubtree(take1);
    // keysum(take1, 9);
    // Node<int> *head = BSTtoLL(take1);
    // while (head != NULL)
    // {
    //     cout << head->data << " ";
    //     head = head->next;
    // }
    // vector<int> *rootnode = roottonode(take1, 12);
    // for (int i = 0; i < rootnode->size(); i++)
    // {
    //     cout << rootnode->at(i) << " ";

    // int store = LCA_BST(take1, 60, 90);
    // cout << store;

    // SUMRTOL_node(take1, 26);

    PrintatDk(take1,50,2);
}