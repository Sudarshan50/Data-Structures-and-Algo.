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
vb vis(N,false);
vi val(N),wt(N);
vvi dp(N,vi(N,-1));


signed main() 
{
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    vi dp(n,mod);
    dp[0] = 0;
    rep(i,0,n)
    {
        rep(j,0,i)
        {
            if (i<=j+a[j])
            {
                dp[i] = min(dp[i],1+dp[j]);
            }
        }
    }
    cout<<dp[n-1]<<endl;
}