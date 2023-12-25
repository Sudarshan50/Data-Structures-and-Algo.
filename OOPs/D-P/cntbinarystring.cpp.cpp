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
#define int long long int



signed main()
{
    int n;cin>>n;
    n+=1;
    vi dp(n+1,-1);
    dp[0]=1;
    dp[1] =1;
    rep(i,2,n+1)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    cout<<flush;
}