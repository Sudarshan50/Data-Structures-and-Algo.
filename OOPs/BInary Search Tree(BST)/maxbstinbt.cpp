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
class info
{
    public:
        int size;
        int min;
        int max;
        int ans;
        bool isBst;
};

info maxbst(node* root)
{
    if (!root)
    {
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if (!root->ll && !root->rr)
    {
        return {1,root->data,root->data,1,true};
    }
    info leftsub = maxbst(root->ll);
    info rightsub = maxbst(root->rr);
    info curr;
    curr.size = leftsub.size+rightsub.size+1;
    if (leftsub.isBst && rightsub.isBst && leftsub.max <root->data && rightsub.min >root->data)
    {
        curr.min = min(leftsub.size,min(rightsub.size,curr.size));
        curr.min = max(leftsub.size,max(rightsub.size,curr.size));
        curr.isBst = true;
        curr.ans = curr.size;
        return curr;
    }
    curr.ans = max(leftsub.size,rightsub.size);
    curr.isBst = false;
    return curr;
}




signed main()
{
    node* root1 = new node(15);
    root1->ll = new node(20);
    root1->ll->ll = new node(5);
    root1->rr = new node(30);

    cout<<maxbst(root1).ans<<endl;
    

    node* root2 = new node(5);
    root2->ll = new node(3);
    root2->rr = new node(6);
    root2->ll->ll = new node(2);
    root2->ll->rr = new node(4);
    br;
    cout<<maxbst(root2).ans<<endl;
    
}