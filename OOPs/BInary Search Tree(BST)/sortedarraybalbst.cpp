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

node* sortedarraytobst(int arr[],int start,int end)
{
    if (start>end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    node* root = new node(arr[mid]);
    root->ll = sortedarraytobst(arr,start,mid-1);
    root->rr = sortedarraytobst(arr,mid+1,end);
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
    int arr[] = {10,20,30,40,50};
    node* root = sortedarraytobst(arr,0,4);
    preorder(root);
}