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
    ~TreeNode()
    {
        for(int i=0; i<children.size(); i++)
        {
            delete children[i];
        }
    }

};

TreeNode<int> *Takedata()
{
    cout<<"Enter rooot data ";
    int rootdata;
    cin>>rootdata;
    TreeNode<int> *root =new TreeNode<int>(rootdata);

    queue<TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);

    while(pendingnodes.size() !=0)
    {
        TreeNode<int>*front = pendingnodes.front();
        pendingnodes.pop();

        int n;
        cout<<"enter the number of children of "<<front->data<<" ";
        cout<<endl;
        cin>>n;
        cout<<endl;

        for(int i=0; i<n; i++)
        {
            int childdata;
            cout<<"Enter the "<<i<<" th child of "<<front->data<<endl;
            cin>>childdata;

            TreeNode<int>* child = new TreeNode<int>(childdata);
            pendingnodes.push(child);
            front->children.push_back(child);
        }
    }
    return   root;


}


// we can also do the same thing in destructor
void del(TreeNode<int> *root)
{
    for(int i=0; i<root->children.size(); i++)
    {
        del(root->children[i]);
    }
    delete root;
}

void pre_order(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<",";

    for(int i=0; i<root->children.size(); i++)
    {
        pre_order(root->children[i]);
    }
}




int main()
{
    TreeNode<int> *take = Takedata();
    // pre_order(take);
    
    del(take);

   // delete root; // for destructor 


    




    return 0;
}