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
int calcheight(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lefthe = calcheight(root->ll);
    int righthe = calcheight(root->rr);
    return (max(lefthe,righthe)+1);
}
// Unoptimes binarytree time omplexity -- o(n2);
int diameter(node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int lefthe = calcheight(root->ll);
    int rigthe = calcheight(root->rr);
    int currdiam = lefthe+rigthe+1;
    int leftdiameter = diameter(root->ll);
    int rightdiameter = diameter(root->rr);
    return (max(currdiam,max(leftdiameter,rightdiameter)));
}
int diameteroptimised(node* root, int* height)
{
    int lhe,rhe = 0;
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int leftdiam = diameteroptimised(root->ll,&lhe);
    int rightdiam = diameteroptimised(root->rr,&rhe);
    int currdiam = lhe+rhe+1;
    *height = max(lhe,rhe)+1;
    return max(currdiam,max(leftdiam,rightdiam));
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
    // cout<<calcheight(root);
    // cout<<diameter(root);
    int height = 0;
    cout<<diameteroptimised(root,&height);

}