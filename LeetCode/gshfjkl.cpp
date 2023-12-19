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
void inorder(node* root,vector<int> &a)
    {
        if(root == NULL)
        {
            return ;
        }
        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);
    }
node* bstfrominorder(vector<int> &a,int start,int end)
{
    node* root;
    if(start>end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    root= new node(a[mid]);
    root->left = bstfrominorder(a,start,mid-1);
    root->right = bstfrominorder(a,mid+1,end);
    return root;
}
void correctBST(node* &root )
{
    vector<int> a;
    inorder(root,a);
    sort(a.begin(),a.end());
    root = NULL;
    int n = a.size();
    root = bstfrominorder(a,0,n-1);
}

bool isBst(node* root,node* min = NULL,node* max = NULL)
{
    if (root == NULL)
    {
        return true;
    }
    if (max && root->data > max->data)
    {
        return false;
    }
    if (min && root->data < min->data)
    {
        return false;
    }
    bool left = isBst(root->ll,min,root);
    bool right = isBst(root->rr,root,max);
    return left and right;
}
void inorder(node* root)
{
    if (!root)
    {
        return;
    }
    inorder(root->ll);
    cout<<root->data<<" ";
    inorder(root->rr);
}
signed main()
{
    node* root = new node(10);
    root->ll = new node(5);
    root->rr = new node(8);
    root->ll->ll = new node(2);
    root->ll->rr = new node(20);
    inorder(root);
    br;
    cout<<isBst(root)<<endl;
    correctBST(root);
    inorder(root);
    br;
    cout<<isBst(root)<<endl;
}