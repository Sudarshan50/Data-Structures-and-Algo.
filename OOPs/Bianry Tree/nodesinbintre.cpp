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
//Recurisive Way...
int nodecountrecur(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    return (nodecountrecur(root->ll)+nodecountrecur(root->rr)+1);
}
int nodesummer(node* root)
{

    if(root == NULL)
    {
        return 0;
    }
    return(nodesummer(root->ll))+(nodesummer(root->rr)+root->data);
}

//Iterative Way...
void nodecounter(node* root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int lvl =0;
    int nodes = 0;
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            nodes++;
            if (temp->ll)
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
            // nodes++;
            q.push(NULL);
            lvl++;
            cout<<lvl<<"->"<<nodes<<endl;
            nodes = 0;
        }
        else
        {
            lvl++;
            cout<<lvl<<"->"<<nodes<<endl;
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
    // nodecounter(root);
    // cout<<nodecountrecur(root)<<endl;
    cout<<nodesummer(root);
}