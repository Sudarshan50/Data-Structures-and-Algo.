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
int search(int arr[],int start,int end,int curr)
{
    int cnt = 0;
    rep(i,start,end)
    {
        if (arr[i] == curr)
        {
            cnt = i;
            break;
        }
    }
    return cnt;
}
node* bitree(int preorder[],int indorder[],int start,int end)
{
    static int idx = 0;
    if (start>end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node* tree = new node(curr);
    if (start == end)
    {
        return tree; 
    }
    else
    {
       int pos = search(indorder,start,end,curr);
        tree->left = bitree(preorder,indorder,start,pos-1);
        tree->right = bitree(preorder,indorder,pos+1,end);
    }
    return tree;
}

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
    int arr1[] = {1,2,4,5,3,6,7};
    int arr2[] = {4,2,5,1,6,3,7};
    node* buildtree = bitree(arr1,arr2,0,6);
    postorder(buildtree);

}