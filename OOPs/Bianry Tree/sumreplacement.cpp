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
void sumreplacement(node* root)
{
    if (root== NULL)
    {
        return;
    }
    sumreplacement(root->ll);
    sumreplacement(root->rr);
    if (root->ll)
    {
        root->data+=root->ll->data;
    }
    if (root->rr)
    {
        root->data+=root->rr->data;
    }
}

void postorder(node* root)
{
    if (root==NULL)
    {
        return;
    }
    postorder(root->ll);
    postorder(root->rr);
    cout<<root->data<<"~";
}
void inorder(node* root)
{
    if (root==NULL)
    {
        return;
    }
    inorder(root->ll);
    cout<<root->data<<"~";
    inorder(root->rr);
}
void preorder(node*root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<"~";
        preorder(root->ll);
        preorder(root->rr);
    }
}


signed main()
{
    node* root = new node(1);
    root->ll = new node(2);
    root->rr = new node(3);
    root->ll->ll = new node(4);
    root->ll->rr = new node(5);
    root->rr->ll = new node(6);
    root->rr->rr = new node(7);
    postorder(root);
    sumreplacement(root);
    br;
    preorder(root);
    // br;
    // inorder(root);
    // br;
    // preorder(root);
}