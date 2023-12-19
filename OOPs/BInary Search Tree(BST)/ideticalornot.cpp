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
bool isbstidentical(node* root1,node* root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    else if (!root1 || !root2)
    {
        return false;
    }
    if (root1->data == root2->data)
    {
        bool left = isbstidentical(root1->ll,root2->ll);
        bool right = isbstidentical(root1->rr,root2->rr);
        if (left and right)
        {
            return true;
        }
    }
    return false;  
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

    node* root1 = new node(1);
    root1->ll = new node(2);
    root1->rr = new node(3);
    root1->rr->rr = new node(5);
    root1->ll->rr = new node(4); 
    root1->ll->rr->ll = new node(6); 
    root1->ll->rr->rr = new node(7); 

    node* root2 = new node(1);
    root2->ll = new node(2);
    root2->rr = new node(3);
    root2->rr->rr = new node(5);
    root2->ll->rr = new node(8); 
    root2->ll->rr->ll = new node(6); 
    root2->ll->rr->rr = new node(7); 

    node* root3 = NULL;
    
    cout<<isbstidentical(root,root1)<<endl;
    br;
    cout<<isbstidentical(root1,root2)<<endl;
}