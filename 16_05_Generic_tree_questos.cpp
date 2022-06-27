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
        TreeNode<int> *front = pendingnodes.front();   // The front is just like a variable dont confuse with it 
                                                        //but it is pointer type which stores the data of  not int,string but of class TreeNode type
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

// count number of nodes and add nodes data
int count(TreeNode<int> *root)
{
    // int ans = root->data;  // to add data of all nodes
    int ans = 1    // to count the number o nodes

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += count(root->children[i]);
    }
    return ans;
}

// print height of a tree (Node vise-edge vise)
int height(TreeNode<int> *root)
{
    int ht= 0;

    for(int i=0; i<root->children.size(); i++)
    {
        int ct = height(root->children[i]);
        {
            if(ct>ht)
            {
                ht = ct;
            }
        }

    }
    ht+=1;
    return ht;  
}
// highest data in a tree;
TreeNode<int> *highest_data(TreeNode<int> *root)
{
    TreeNode<int> *max = new TreeNode<int>(root->data);

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *child = highest_data(root->children[i]);
        if (child->data > max->data)
        {
            max = child;
        }
    }
    return max;
}

// print at level k / depth of node

void printatlevelk(TreeNode<int> *root,int k)
{
    if(k==0)
    {
        cout<<root->data<<endl;
    }

    for(int i=0; i<root->children.size(); i++)
    {
        printatlevelk(root->children[i],k-1);
    }
}

//count leaf nodes

int leaf_node(TreeNode<int> * root)
{
    int count =0;
    if(root->children.size()==0)
    {
        return 1;
    }

    for(int i=0; i<root->children.size(); i++)
    {
       count += leaf_node(root->children[i]);
    }
    
    return count;


}

// contain x

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

// greater than x count
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
    int sum = root->data;
    for(int i =0; i<root->children.size(); i++)
    {
        sum +=root->children[i]->data;
    }
    return sum;

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

// identical tree;

bool identicall(TreeNode<int> *root1,TreeNode<int>* root2)
{
    if(root1==NULL)
    {
        if(root2==NULL)
        {
            return root1==root2;
        }
    }
    return false;
    if(root1->data != root2->data)
    {
        return false;
        
    }
    int size1 = root1->children.size();
    int size2 = root2->children.size();
    if(size1!=size2)
    {
        return false;
    }
    for(int i=0; i<size1; i++)
    {
        if(!identicall(root1->children[i],root2->children[i]));
        {
            return false;
        }

    }
    return true;
}

// next larger value

TreeNode <int> *next_larger(TreeNode<int> *root,int k)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->children.size()==0)
    {
        if(root->data>k)
        {
            return root;
        }
        return NULL;

    }
    TreeNode<int> *result = NULL;
    if(root->data >k)
    {
        result = root;
    }

    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int> *temp = next_larger(root->children[i],k);

        if(temp==NULL)
        {
            continue;
        }
        if(result == NULL || temp->data<result->data)   //bcz we know that both are already bigger than k
                                                        // now we have to decide whether temp or result is closer to k
        {
            result = temp;
        }
        
    }
    return result;
}

// second largest 

TreeNode<int> *Second_largest(TreeNode<int>*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->children.size()==0)
    {
        return  NULL;
    }
    TreeNode<int> *larger= root;
    TreeNode<int> *second_larger = root->children[0] ;

    if(larger->data <second_larger->data)
    {
        larger = root->children[0];
        second_larger = root;
    }

    queue<TreeNode<int>* > pendingnodes;
    pendingnodes.push(root);

    while(pendingnodes.size()!=0)
    {
        TreeNode<int> * front= pendingnodes.front();
        pendingnodes.pop();

        for(int i=0; i<front->children.size(); i++)
        {
            if(front->children[i]->data>second_larger->data)
            {
                if(front->children[i]->data>larger->data)
                {
                    second_larger = larger;
                    larger = front->children[i];
                }
            }
            else
            {
                second_larger = front->children[i];
            }

        }

    }
    return second_larger;
}

 void  replacewihdepth( TreeNode<int> *root,int value)
 {
     if(root ==   NULL)
     {
        return;
     }

     root->data = value;

     for(int i=0; i<root->children.size(); i++)
     {
        replacewihdepth(root->children[i],value +1);
     }
 }




void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> print;
    print.push(root);

    while (print.size() != 0)
    {
        TreeNode<int> *front = print.front();
        print.pop();

        cout << front->data << " : ";

        for (int i = 0; i < front->children.size(); i++)
        {
            print.push(front->children[i]);
            cout << front->children[i]->data << ",";
        }
        cout << endl;
    }
}

int main()
{

    TreeNode<int> *take = Takedata_levelwise();
    // TreeNode<int> *take2 = Takedata_levelwise();
    // print(take);
    // cout << highest_data(take)->data;
    // printatlevelk(take,2);
    // cout<<isIdentical(take,take2);
    // cout<<next_larger(take,21)->data;
    // cout<<Second_largest(take)->data;
    replacewihdepth(take,0);
    print(take);

    return 0;

    
}

//