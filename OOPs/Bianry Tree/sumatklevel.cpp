#include<iostream>
#include<queue>
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
void superksummer(node* root)
{
    if (root == NULL )
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int lvl = 0;
    int sum = 0;
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if (temp!= NULL)
        {
            sum+=temp->data;
            if(temp->ll)
            {
                q.push(temp->ll);
            }
            if (temp->rr)
            {
                q.push(temp->rr);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            cout<<lvl<<"->"<<sum<<endl;
            sum = 0;
            lvl++;
        } 
        else
        {
            lvl++;
            cout<<lvl<<"->"<<sum<<endl;
        }

    }
}

signed main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->ll->rr = new node(5);
    root->rr->ll = new node(6);
    root -> rr->rr = new node(7);
    superksummer(root);
}