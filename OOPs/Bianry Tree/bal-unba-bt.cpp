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
bool balchecker(node* root,int* height)
{
    if (root == NULL)
    {
        *height = 0;
        return true;
    }
    int lhe,rhe = 0;
    if(balchecker(root->left,&lhe) == false)
    {
        return false;
    }
    if(balchecker(root->rr,&rhe) == false)
    {
        return false;
    }
    *height = max(lhe,rhe)+1;
    if (abs(lhe-rhe)>1)
    {
        return false;
    }
    else
        return true;
}
signed main()
{
    node* root1 = new node(1);
    root1->ll = new node(2);
    root1->rr = new node(3);
    root1->ll->ll = new node(4);
    root1->ll->rr = new node(5);
    root1->rr->ll = new node(6);
    root1->rr->rr = new node(7);
    node* root2 = new node(1);
    root2->ll = new node(2);
    root2->ll->ll = new node(3);
    int height = 0;
    cout<<balchecker(root1,&height);
    br;
    cout<<balchecker(root2,&height);
    br;
}