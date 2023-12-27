//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++



class node
{
    public:
        node* next[2];
        node()
        {
            next[0] = NULL;
            next[1] = NULL;
        }
};
void insert(int n,node* &ans)
{
    node* it = ans;
    for(int i =31;i>=0;i--)
    {
        int bit = (n>>i) &1;
        if(!it->next[bit])
        {
            it->next[bit] = new node();
        }
        it = it->next[bit];
    }
}
int query(int n,node* trie)
{
    int ans= 0;
    node* it = trie;
    for(int i =31;i>=0;i--)
    {
        int bit = ((n>>i) &1)?0:1;
        if(it->next[bit])
        {
            ans |= (1<<i);
            it = it->next[bit];
        }
        else
        {
            it = it->next[bit xor 1];
        }
    }
    return ans;
}
int maxSubarrayXOR(int N, int arr[])
{
    node* root = new node();
    insert(0,root);
    int ans = query(arr[0],root);
    insert(arr[0],root);
    int it = 0;
    for(int i =1;i<N;i++)
    {
        it^= arr[i];
        ans = max(ans,query(it,root));
        insert(arr[i],root);
    }
    return ans;
}
signed main()
{
    int arr[] = {1,2,3,4};
    cout<<maxSubarrayXOR(4,arr)<<endl;
}
