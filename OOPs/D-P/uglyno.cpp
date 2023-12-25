#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 100000007;
const int N = 1e5+2;
#define mk unordered_map<int,int>
vector<int> parent(N);


signed main()
{
    int n;cin>>n;
    int c2(0),c3(0),c5(0);
    vi dp(n+1,1);
    rep(i,1,n+1)
    {
        dp[i] = min({2*dp[c2], 3*dp[c3], 5*dp[c5]});
        if (2*dp[c2] == dp[i])
        {
            c2++;
        }
        if (3*dp[c3] == dp[i])
        {
            c3++;
        }
        if (5*dp[c5] == dp[i])
        {
            c5++;
        }
    }
    cout<<dp[n-1]<<endl;
}