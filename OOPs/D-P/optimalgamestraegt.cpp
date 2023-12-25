#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9+7;
const int N = 1e2+2;
#define mk unordered_map<int,int>
vector<int> parent(N);
vi a(N);
vvi dp(N,vi (N,-1));

int ogs(int i,int j)
{
    if(i==j)
    {
        return 1;
    }
    if (i>j)
    {
        return 0;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int l  = a[i]+ min(ogs(i+2,j),ogs(i+1,j-1));
    int r = a[j] + min(ogs(i,j-2),ogs(i+1,j-1));
    dp[i][j] = max(l,r);
    return dp[i][j];
}


signed main()
{
    int n;cin>>n;
    rep(i,0,n)
    {
        cin>>a[i];
    }
    cout<<ogs(0,n-1)<<endl;
}