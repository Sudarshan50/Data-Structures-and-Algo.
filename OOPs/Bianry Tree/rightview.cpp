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
void rightview(node* root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        rep(i,0,n)
        {
            node* temp = q.front();
            q.pop();
            if (i== n-1)
            {
                cout<<temp->data<<" ";
            }
            if (temp->ll !=NULL)
            {
                q.push(temp->ll);
            }
            if (temp->rr != NULL)
            {
                q.push(temp->rr);
            }
        }
    }
}

signed main()
{
    node* root = new node(1);
    root->ll = new node(2);
    root->rr = new node(3);
    root->ll->ll = new node(4);
    root->ll->rr = new node(5);
    root->rr->ll = new node(5);
    root->rr->rr = new node(6);
    root->rr->ll->ll = new node(7);
    rightview(root);

}