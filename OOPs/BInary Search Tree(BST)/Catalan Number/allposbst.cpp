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
vector<node*> allposbst(int start,int end)
{
    vector<node*>trees;
    if (start>end)
    {
        trees.push_back(NULL);
        return trees;
    }
    rep(i,start,end+1)
    {
        vector<node*> leftsubtrees = allposbst(start,i-1);
        vector<node*> rightsubtress = allposbst(i+1,end);
        rep(j,0,leftsubtrees.size())
        {
            node* left = leftsubtrees[j];
            rep(k,0,rightsubtress.size())
            {
                node* right = rightsubtress[k];
                node * temp = new node(i);
                temp->rr = right;
                temp->ll = left;
                trees.push_back(temp);
            }
        }
    } 
    return trees;  
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
    vector<node*>roots = allposbst(1,3);
    rep(i,0,5) // NUmber of possible bst is given by catalan number....
    {
        cout<<i<<":- ";
        preorder(roots[i]);
        br;
    }
}