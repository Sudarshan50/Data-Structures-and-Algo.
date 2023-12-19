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
node* inordersuc(node* root)
{
    node* curr = root;
    while (curr && curr->ll != NULL)
    {
        curr = curr->ll;
    }
    return curr;
}
node* delbst(node* root,int key)
{
   if (key>root->data)
   {
        root->rr = delbst(root->rr,key);
   }
   else if (key<root->data)
   {
        root->ll = delbst(root->ll,key);
   }
   else
   {
        if (root->ll == NULL)
        {
            node* temp = root->rr;
            free(root);
            return temp;
        }
        else if (root-> rr == NULL)
        {
            node* temp = root->ll;
            free(root);
            return temp;
        }
        node* temp = inordersuc(root->right);
        root->data = temp->data;
        root->rr = delbst(root->right,temp->data);
   }
    return root;  
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
    indorder(root);
    br;
    root= delbst(root,4);
    indorder(root);
}