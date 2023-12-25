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
vi dp(N,-1);


//Memoization
int fib(int n)
{
    if(n == 0 || n==1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n] = fib(n-1)+fib(n-2);
    return dp[n];
}

signed main()
{
    int n;
    cin>>n;
    dp[0] = 0;dp[1] = 0;dp[2] =1;
    rep(i,3,n+1)
    {
        dp[i] = dp[i-1] +dp[i-2]; // Via DP table....(Tabultaion)
    } 
    cout<<dp[n]<<endl;
}