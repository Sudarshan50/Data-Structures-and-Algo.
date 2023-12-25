#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define int long long int
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9+7;
const int N = 1e5+2;
#define mk unordered_map<int,int>
vector<int> parent(N);
vb vis(N,false);
vi dp(N,mod);

//Memoization Appraoch.....

int minsq(int n)
{
    if(n==0 || n==1 || n==2 || n==3)
    {
        return n;
    }
    if(dp[n] != mod)
    {
        return dp[n];
    }
    for(int i = 1;i*i<=n;i++)
    {
        dp[n] = min(dp[n],1+minsq(n-(i*i)));
    }
    return dp[n];
}

signed main()
{
    int n;cin>>n;
    cout<<minsq(n)<<endl;
}