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

TrieNode* insertinTrie(vi &a)
{
    TrieNode* root = new TrieNode();
    rep(i,0,a.size())
    {
        int curr = a[i];
        TrieNode* it = root;
        for(int i =31;i>=0;i--)
        {
            int bit = (curr >> i) &1;
            if (!it->next[bit]) 
            {
                it->next[bit] = new TrieNode();
            }
            it = it->next[bit];
        }
    }
    return root;
}
int maxorsubr(TrieNode* trienode,vi &a)
{
    int res = 0;
    rep(i,0,a.size())
    {
        int curr = a[i];
        int maxi= 0;
        TrieNode* it =trienode;
        for(int i =31;i>=0;i--)
        {
            int bit = ((curr >> i) & 1)? 0:1;
            if (it->next[bit])
            {
                maxi <<= 1;
                maxi |= 1;
                it = it->next[bit];
            }
            else
            {  
                maxi <<= 1;
                maxi |= 0;
                it =it->next[bit xor 1];
            }
        }
        res = max(res,maxi);
    }
    return res;
}

signed main()
{
    vi a = {1,2,3,4,5,6,22,33,44,22,111};
    TrieNode* root = insertinTrie(a);
    int ans = maxorsubr(root,a);
    cout<<ans<<endl;
}