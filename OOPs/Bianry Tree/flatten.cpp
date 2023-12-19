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
void flatten(node* root)
{
    if (root== NULL || (root->ll == NULL && root->rr ==NULL))
    {
        return;
    }
    if (root->left)
    {
        flatten(root->ll);
        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        node* it = root->right;
        while (it->right)
        {
            it= it->right;
        }
        it->right = temp;
    }
    flatten(root->right);
}
void preorder(node* root)
{
    if (root== NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->ll);
    preorder(root->rr);
}
void inorder(node* root)
{
    if (root== NULL)
    {
        return;
    }
    preorder(root->ll);
    cout<<root->data<<" ";
    preorder(root->rr);

}
signed main()
{
    node* root = new node(4);
    root->ll = new node(9);
    root->rr = new node(5);
    root->ll->ll = new node(1);
    root->ll->rr = new node(3);
    root->rr->ll = new node(6);
    // root->rr->rr = new node(6);
    // root->rr->ll->ll = new node(7);
    inorder(root);
    br;
    flatten(root);
    inorder(root);

}