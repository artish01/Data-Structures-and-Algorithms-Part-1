#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

TreeNode<int> *Takedata_levelwise()
{
    cout << "Enter root data ";
    int rootdata;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);

    queue<TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        TreeNode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        cout << "Enter the number of children of " << front->data << endl;
        int child;
        cin >> child;

        for (int i = 0; i < child; i++)
        {
            int childdata;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            front->children.push_back(child); // vector add
            pendingnodes.push(child);
        }
    }
    return root;
}

int containx(TreeNode<int> *root,int k)
{
    if(root==NULL)
    {
        return false;
    }
   if(root->data==k)
   {
       return true;
   }


    for (int i = 0; i < root->children.size(); i++)
    {
            if((root->children[i], k))
            {
                return true;
            }
    }
    return false;
}

int greaterthanx(TreeNode<int>*root,int k)
{
    int count=0;
    if(root->data>k)
    {
        count++;
    }

    for(int i=0; i<root->children.size(); i++)
    {
        count+=greaterthanx(root->children[i],k);
    }
    return count;
}

int nodesum(TreeNode<int> *root)
{
    int data = root->data;

    for(int i=0; i<root->children.size(); i++)
    {
        data +=root->children[i]->data;

    }
    return data;

}
// maximun child node  sum

TreeNode<int> *max_childsum(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    TreeNode<int> *result = root;
    int maxsum= nodesum(root);

    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int> *temp = max_childsum(root->children[i]);
        int sum = nodesum(temp);

        if(sum>maxsum)
        {
            maxsum = sum;
            result = temp;


        }
    }
    return result;

}



// void print(TreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     queue<TreeNode<int> *> print;
//     print.push(root);

//     while (print.size() != 0)
//     {
//         TreeNode<int> *front = print.front();
//         print.pop();

//         cout << front->data << " : ";

//         for (int i = 0; i < front->children.size(); i++)
//         {
//             print.push(front->children[i]);
//             cout << front->children[i]->data << ",";
//         }
//         cout << endl;
//     }
// }

int main()
{

    TreeNode<int> *take = Takedata_levelwise();
    cout<<max_childsum(take)->data;

    return 0;
}



//