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
int maxsumutil(node* root,int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxsumutil(root->ll,ans);
    int right = maxsumutil(root->rr,ans);
    int nodeMax = max( max(root->data , root->data+left+right) ,
                        max(root->data+left ,root->data+right));
    ans = max(ans,nodeMax);
    int singlepathSum = max(root->data,max(root->data+left,root->data+right));
    return singlepathSum;
}
int maxpsum(node* root)
{
    int ans = INT_MIN;
    maxsumutil(root,ans);
    return ans;
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
    // root->rr->ll->ll = new node(8);
    cout<<maxpsum(root);
    br;
}