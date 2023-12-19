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
node* bitree(int postorder[],int inorder[],int start,int end)
{
    static int idx = end;
    int curr = postorder[idx];
    node* bintree = new node(curr);
    if (start>end)
    {
        return NULL;
    }
    if(idx)
    {
        idx--;
        if (start == end)
        {
            return bintree;
        }
        int pos = search(inorder,start,end,curr);
        bintree->right = bitree(postorder,inorder,pos+1,end);
        bintree->left = bitree(postorder,inorder,start,pos-1);
    }
    return bintree;
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
    int postor[] ={4,5,2,6,7,3,1};
    int inord[] = {4,2,5,1,6,3,7};
    node* buildtree = bitree(postor,inord,0,6);
    postorder(buildtree);

}