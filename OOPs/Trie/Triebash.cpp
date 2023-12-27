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
    for(int i = 31;i>=0;i--)
    {
        int bit = ((n>>i) & 1)?0:1; 
        if (it->next[bit])
        {
            ans |= 1<<i;
            it = it->next[bit];
        }
        else
        {
            it = it->next[bit xor 1];
        }
    }
    return ans;
}

signed main()
{
    trie = new node();
    insert(0);
    int n;cin>>n;
    vi a(n);
    rep(i,0,n){cin>>a[i];}
    vi rmax(n+1);
    int it(0);
    for(int i =n-1;i>=0;i--)
    {
        it^=a[i];
        if (i!=n-1)
        {
            rmax[i] = max(rmax[i+1],query(it));
            insert(it);
        }
        else
             rmax[i]= query(it);
             insert(it);
    }
    free(trie);
    trie = new node();
    insert(0);
    int l(0);
    int ans = 0;
    rep(i,0,n)
    {
        l^=a[i];
        ans = max(ans,rmax[i+1]+query(l));
        insert(l);
    }
    cout<<ans<<endl;

}