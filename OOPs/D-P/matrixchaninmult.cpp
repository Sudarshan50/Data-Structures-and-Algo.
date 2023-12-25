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
int n;

int mcm(vi &a,int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    dp[i][j] = mod; 
    rep(k,i,j)
    {
        dp[i][j] = min(dp[i][j], a[i]*a[k]*a[j] + mcm(a,i+1,k)+mcm(a,k+1,j));
    }
    return dp[i][j];
}



signed main()
{
    cin>>n;
    vi a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    cout<<mcm(a,0,n-1)<<endl;
}