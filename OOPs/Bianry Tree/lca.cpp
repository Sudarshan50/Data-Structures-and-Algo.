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
bool getPath(node* root,int key,vi &path)
{
    if (root== NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }
    if (getPath(root->ll,key,path) || getPath(root->rr,key,path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int lca(node* root,int n1,int n2)
{
    vi path1,path2;
    if (!getPath(root,n1,path1) || !getPath(root,n2,path2))
    {
        return -1;
    }
    int pc;
    for(int pc = 0;(pc<path1.size() && pc<path2.size());pc++)
    {
        if (path1[pc]!= path2[pc])
        {
            break;
        }
    }
    return path1[pc];
} 

node* lcaopt(node* root,int n1,int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node* leftlca = lcaopt(root->ll,n1,n2);
    node* rightlca = lcaopt(root->rr,n1,n2);
    if (leftlca && rightlca)
    {
        return root;
    }
    if (leftlca)
    {
        return leftlca;
    }
    return rightlca;
}
void preorer(node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorer(root->ll);
    preorer(root->rr);
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
    root->rr->ll->ll = new node(8);
    preorer(root);
    br;
    int n1 = 6;
    int n2 = 7;
    cout<<lca(root,5,6);
    br;
    node* pig = lcaopt(root,n1,n2);
    cout<<pig->data;
}