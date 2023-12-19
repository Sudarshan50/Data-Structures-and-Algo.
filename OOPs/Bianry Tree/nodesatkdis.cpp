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
void printnodesatk(node* root,int k)
{
    if (root == NULL || k<0)
    {
        return;
    }
    if (k == 0)
    {
        cout<<root->data<<" ";
        return;
    }
    printnodesatk(root->ll,k-1);
    printnodesatk(root->rr,k-1);
}
int nodesatk(node* root,node* target,int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printnodesatk(root,k);
        return 0;
    }
    int dl = nodesatk(root->ll,target,k);
    if (dl!=-1)
    {
        if (dl+1 == k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printnodesatk(root->rr,k-dl-2);
        }
        return 1+dl;
    }
    int dr = nodesatk(root->rr,target,k);
    if (dr!=-1)
    {
        if (dr+1 == k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printnodesatk(root->ll,k-dr-2);
        }
        return 1+dr;
    }    
    return -1;
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
    cout<<nodesatk(root,root->ll,3);
    // printnodesatk(root,2);

}