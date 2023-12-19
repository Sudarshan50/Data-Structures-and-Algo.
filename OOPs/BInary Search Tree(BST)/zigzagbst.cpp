#include<iostream>
#include<stack>
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
void zigzagbst(node* root)
{
    if (root==NULL)
    {
        return;
    }
    stack<node*> currlvl;
    stack<node*> nextlvl;
    currlvl.push(root);
    bool lefttoright = true; 
    while (!currlvl.empty())
    {
        node* temp = currlvl.top();
        currlvl.pop();
        if (temp)
        {
            cout<<temp->data<<" ";
            if (lefttoright)
            {
                if (temp->ll)
                {
                    nextlvl.push(temp->ll);
                }
                if (temp->rr)
                {
                    nextlvl.push(temp->rr);
                }  
            }
            else
            {
                if (temp->rr)
                {
                    nextlvl.push(temp->rr);
                }
                if (temp->ll)
                {
                    nextlvl.push(temp->ll);
                }
            }
            if (currlvl.empty())
            {
                lefttoright= !lefttoright;
                swap(currlvl,nextlvl);
            }
        }
    }
}

signed main()
{
    node* root = new node(1);
    root->ll = new node(2);
    root->rr = new node(3);
    root->rr->rr = new node(5);
    root->ll->rr = new node(4); 
    root->ll->rr->ll = new node(6); 
    root->ll->rr->rr = new node(7); 
    zigzagbst(root);
    br;
}