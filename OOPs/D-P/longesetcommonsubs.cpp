#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9+7;
const int N = 1e3+2;
#define mk unordered_map<int,int>
vector<int> parent(N);
vvi dp(N,vi(N,-1));

int longestcomonsubs(vector<char> &a,vector<char> & b,int n,int m)
{
    if(n<=0 || m<=0)
    {
        return 0;
    }
    if(dp[n][m] !=-1)
    {
        return dp[n][m];
    }
    if (a[n-1] == b[m-1])
    {
        dp[n][m] = 1+longestcomonsubs(a,b,n-1,m-1);
    }
    else
    {
        dp[n][m] = max(longestcomonsubs(a,b,n-1,m),longestcomonsubs(a,b,n,m-1)); 
    }
    return dp[n][m];
}

signed main()
{
    int n,m;
    cin>>n>>m;
    vector<char> s1(n);
    vector<char> s2(m);
    rep(i,0,n)
    {
        cin>>s1[i];
    }
    rep(i,0,m)
    {
        cin>>s2[i];
    }
    cout<<longestcomonsubs(s1,s2,n,m);
}