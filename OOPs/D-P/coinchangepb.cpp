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
vvi dp(N,vi(N,-1));

int coinchange(vi &a,int n,int k)
{
    if(k == 0)
    {
        return 1;
    }
    if(n<=0 || k<0)
    {
        return 0;
    }
    if(dp[n][k]!= -1)
    {
        return dp[n][k];
    }
    dp[n][k] = coinchange(a,n,k-a[n-1]) + coinchange(a,n-1,k);
    return dp[n][k];
}


signed main()
{
    int n,k;
    cin>>n>>k;
    vi a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    cout<<coinchange(a,n,k)<<endl;
}