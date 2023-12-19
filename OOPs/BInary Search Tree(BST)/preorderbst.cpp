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
node* preorderbst(int preorder[],int *preorderidx,int key,int min,int max,int n)
{
    if (*preorderidx>=n)
    {
        return NULL;
    }
    node* root = NULL;
    if (key>min && key<max)
    {
        root = new node(key);
        *preorderidx = *preorderidx+1;
        if (*preorderidx<n)
        {
            root->ll = preorderbst(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if (*preorderidx<n)
        {
            root->rr = preorderbst(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
    return root;
}
void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->ll);
    preorder(root->rr);
}
signed main()
{
    int arr[] = {10,2,1,13,11};
    int preorderidx = 0;
    node* root = preorderbst(arr,&preorderidx,arr[0],INT_MIN,INT_MAX,5);
    preorder(root);
    br;

}