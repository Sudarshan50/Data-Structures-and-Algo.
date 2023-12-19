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
node* mergebt(node* root1,node* root2)
{
    if(root1==NULL && root2 ==  NULL)
    {
        return NULL;
    } 
    queue<node*> q,p;
    q.push(root1);
    p.push(root2);
    while (!q.empty())
    {
        node* ptr1  = q.front();
        node* ptr2 = p.front();
        q.pop();
        p.pop();
        if (ptr1 && ptr2)
        {
            ptr1->data+=ptr2->data;
            q.push(ptr1);
            p.push(ptr2);
        }
        if (ptr1->ll && ptr2->ll)
        {
            ptr1->ll->data+=ptr2->ll->data;
            q.push(ptr1);
            p.push(ptr2);
        }
        if (ptr1->rr && ptr2->rr)
        {
            ptr1->rr->data+=ptr2->rr->data;
            q.push(ptr1);
            p.push(ptr2);
        }
        if(ptr1 && !ptr2)
        {
            q.push(ptr1);
        }
        if (!ptr1 && ptr2 )
        {
            q.push(ptr2);
        }
        
        
        
        
    }
    
    
}