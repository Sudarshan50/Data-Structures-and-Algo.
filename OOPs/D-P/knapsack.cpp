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

//n - element m -- max weight 
int knapsack(int n,int m)
{
    if (n<=0 || m<=0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (wt[n-1]>m)
    {
        dp[n][m] = knapsack(n-1,m);
    }
    else
        dp[n][m] = max(knapsack(n-1,m),knapsack(n-1,m-wt[n-1])+val[n-1]);
    return dp[n][m];
}

signed main()
{
    int n,m;
    cin>>n;
    rep(i,0,n)
    {
        cin>>wt[i];
    }
    rep(i,0,n)
    {
        cin>>val[i];
    }
    cin>>m;
    cout<<knapsack(n,m)<<endl;
}