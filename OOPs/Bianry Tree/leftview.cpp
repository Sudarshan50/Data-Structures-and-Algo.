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
void leftview(node* root)
{
    if (root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        rep(i,0,n)
        {
            node* curr = q.front();
            q.pop();
            if (i == 0)
            {
                cout<<curr->data<<" ";
            }
            if (curr->ll)
            {
                q.push(curr->ll);
            }
            if (curr->rr)
            {
                q.push(curr->rr);
            }   
        }
    }
}

signed main()
{
    node* root = new node(5);
    root->ll = new node(3);
    root->rr = new node(6);
    root->ll->ll = new node(2);
    root->ll->rr = new node(4);
    leftview(root);
    br;

}