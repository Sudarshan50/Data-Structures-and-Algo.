#include<iostream>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define br cout<<endl
#define ll left 
#define rr right

class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int val)
        {
            data = val;
            left = NULL;
            right= NULL;
        }
};
//----------Wrong approach failing at bst -- 4,2,1,7,3,8---------

// bool checkbst(node* root)
// {
//     if (root == NULL || (root-> ll == NULL && root->rr == NULL))
//     {
//         return false;
//     }
//     if (root->ll->data < root->data && root->rr->data > root->data)
//     {
//         return true;
//     }
//     else
//     {
//         return checkbst(root->ll);
//         return checkbst(root->rr);
//     }
//     return false;
// }
bool checkbst(node* root,node* min,node* max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max!= NULL && root->data >= max->data )
    {
        return false;
    }
    bool left = checkbst(root->ll,min,root);
    bool right = checkbst(root->rr,root,max);
    return left and right;
}
node* bst(node* root,int val)
{
    if (root== NULL)
    {
        root = new node(val);
    }
    if (root->data >val)
    {
        root->ll = bst(root->ll,val);
    }
    if (root->data <val)
    {
        root->rr = bst(root->rr,val);
    }
    return root;
}
void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->ll);
    preorder(root->rr);
}

signed main()
{
    node* min = new node(INT_MIN);
    node* max = new node(INT_MAX);
    // node* min = new node(INT_MIN);
    // node* max = new node(INT_MAX);
    node* root1 = new node(15);
    root1->ll = new node(20);
    root1->ll->ll = new node(5);
    root1->rr = new node(30);
    // preorder(root1);
    cout<<checkbst(root1,min,max);
    br;
    node* root2 = new node(1);
    root2->ll = new node(2);
    root2->rr = new node(3);
    root2->ll->ll = new node(4);
    root2->ll->rr = new node(5);
    root2->rr->ll = new node(6);
    root2->rr->rr = new node(7);
    cout<<checkbst(root2,min,max);
    br;
}