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
void swap(int* a,int *b)
{
    int temp = *a;
    *a= *b;
    *b =temp;
}
void calcptr(node* root,node** first,node** mid,node** last,node** prev)
{
    if (root == NULL)
    {
        return;
    }
    calcptr(root->ll,first,mid,last,prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!(*first))
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcptr(root->rr,first,mid,last,prev);
}
void correctBst(node* root)
{
    node* first,*mid,*last,*prev;
    first = NULL;last = NULL;prev=NULL;mid = NULL;
    calcptr(root,&first,&mid,&last,&prev);
    if (first && last)
    {
        swap(&(first->data),&(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data),&(mid->data));
    }
}
void inorder(node* root)
{
    if (!root)
    {
        return;
    }
    inorder(root->ll);
    cout<<root->data<<" ";
    inorder(root->rr);
}
signed main()
{
    node* root = new node(10);
    root->ll = new node(5);
    root->rr = new node(8);
    root->ll->ll = new node(2);
    root->ll->rr = new node(20);
    inorder(root);
    br;
    correctBst(root);
    inorder(root);
    br;
    
}