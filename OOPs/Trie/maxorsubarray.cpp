#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 100000007;
const int N = 1e5+2;
#define mk unordered_map<int,int>
#define node TrieNode


class TrieNode
{
    public:
        TrieNode* next[2];
        TrieNode()
        {
            next[0] = NULL;
            next[1] = NULL;
        }
};

TrieNode* trie;
void insert(int n)
{
    node* it = trie;
    for(int i =31;i>=0;i--)
    {
        int bit = (n>>i) &i;
        if(!it->next[bit])
        {
            it->next[bit] = new node();
        }
        it =  it->next[bit];
    }
}

int query(int n)
{
    int ans = 0;
    node* it = trie;
    for(int i = 32;i>=0;i--)
    {
        int bit = ((n>>i) & 1)?0:1; 
        if (it->next[bit])
        {
            ans |= 1<<i;
            it = it->next[bit];
        }
        else{
            it = it->next[bit xor 1];
        }
    }
    return ans;
}

int maxxorsubarray(vi &a ,int n)
{
    trie = new node();
    insert(0);
    int ans = query(a[0]);
    insert(a[0]);
    int it(0);
    rep(i,1,n)
    {
        it^=a[i];
        ans = max(ans,query(a[i]));
        insert(it);
    }
    return ans;
}

    signed main()
    {
        vi a = {1,2,3,4};
        cout<<maxxorsubarray(a,4)<<endl;
    }
