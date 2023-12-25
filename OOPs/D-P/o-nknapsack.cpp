#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9+7;
const int N = 1e4+2;
#define mk unordered_map<int,int>
vector<int> parent(N);
vi dp(N,0);


signed main()
{
    int n;cin>>n;
    vi wt(n),val(n);
    rep(i,0,n)
    {
        cin>>wt[i];
    }
    rep(I,0,n)
    {
        cin>>val[I];
    }
    int w;cin>>w;
    rep(i,0,w+1)
    {
        rep(j,0,n)
        {
            if (i-wt[j]>=0)
            {
                dp[i] = max(dp[i],val[j]+dp[i-wt[j]]);
            }
        }
    }
    cout<<dp[w]<<endl;
}