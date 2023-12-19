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
node* insertbst(node* root,int val)
{
    if (root == NULL)
    {
        return (new node(val));
    }
    if (val>root->data)
    {
        root->rr = insertbst(root->rr,val);
    }
    if (val<root->data)
    {
        root->ll = insertbst(root->ll,val);
    }
    return root;
}

bool searchbst(node* root,int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (root->data<key)
    {
        return searchbst(root->rr,key);
    }
    return searchbst(root->ll,key);

}

void indorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    indorder(root->ll);
    cout<<root->data<<" ";
    indorder(root->rr);
}
signed main()
{
    int arr[] = {5,1,3,4,2,7};
    node* root;
    rep(i,0,6)
    {
        if (i == 0)
        {
            root = new node(arr[i]);
        }
        insertbst(root,arr[i]);
    }
    // indorder(root);
    cout<<searchbst(root,-2);
    br;
}