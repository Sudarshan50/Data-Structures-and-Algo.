#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
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
void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<"~";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<"~";
        inorder(root->right);
    }
}
void postorder(node* root)
{
    if (root== NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"~";
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
    preorder(root);
    cout<<endl<<endl;
    inorder(root);
    cout<<endl<<endl;
    postorder(root);
    cout<<endl<<endl;

}