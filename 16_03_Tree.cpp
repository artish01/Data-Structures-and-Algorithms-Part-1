#include <iostream>
// #include "16_02_Tree_class.h"
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;  // this  is pointer vector so we have to use arrow operator while extracting the indices

    TreeNode(T data)
    {
        this->data = data;
    }
};

TreeNode<int>* takeinput()
{
    int rootdata;
    cout<<"Enter data ";
    cin>>rootdata;
    cout<<endl;
    TreeNode<int>*root = new TreeNode<int>(rootdata);
    cout<<"Enter children of "<<rootdata<<" ";
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        TreeNode<int> * child = takeinput();
        root->children.push_back(child);

    }
    return root;

}

void print(TreeNode<int> *root)
{
    if(root==NULL)  // edge case
    {
        return;
    }
    for(int i=0; i<root->children.size(); i++)
    {
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++)
    {
       print(root->children[i]);
    }
    cout<<root->data<<" : ";
}

int main()
{

    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node12 = new TreeNode<int>(4);
    // TreeNode<int> *node13 = new TreeNode<int>(5);
    // TreeNode<int> *node2 = new TreeNode<int>(3);
    // TreeNode<int> *node21 = new TreeNode<int>(6);

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // node1->children.push_back(node12);
    // node1->children.push_back(node13);
    // node2->children.push_back(node21);
    TreeNode<int> *root =  takeinput();
    print(root);

    return 0;
}