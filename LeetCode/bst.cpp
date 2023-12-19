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

void countpair(node* root1,node* root2 ,int x)
{
    queue<node*> q;
    q.push(root1);
    q.push(NULL);
    queue<node*> p;
    p.push(root2);
    p.push(NULL);
    int ctr = 0;
    while (!q.empty() && !p.empty())
    {
        node* temp1 = q.front();
        node* temp2 = p.front();
        if (temp1!= NULL)
        {
            
        }
        
    }
    
}

signed main()
{
    node* root1 = new node(5);
    root1->ll = new node(3);
    root1->rr = new node(7);
    root1->ll->ll = new node(2);
    root1->ll->rr = new node(4);
    root1->rr->ll = new node(6);
    root1->rr->rr = new node(8);

    node* root2 = new node(10);
    root2->ll = new node(6);
    root2->rr = new node(15);
    root2->ll->ll = new node(3);
    root2->ll->rr = new node(8);
    root2->rr->ll = new node(11);
    root2->rr->rr = new node(18);
}