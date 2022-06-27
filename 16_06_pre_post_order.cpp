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
void post_order(TreeNode<int> *root)
{   
    if(root==NULL)
    {
        return ;
    }
    
    for(int i=0; i<root->children.size(); i++)
    {
        post_order(root->children[i]); 
    }
    cout<<root->data<<",";
    
}




int main()
{
    TreeNode<int> *take = Takedata();
    // pre_order(take);
    post_order(take);


    




    return 0;
}