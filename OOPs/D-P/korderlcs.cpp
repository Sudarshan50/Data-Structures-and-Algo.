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
int dp[205][205][205];
string s1,s2,s3;

int lcsink(int n,int m,int k)
{
    if (n<=0 || m<=0)
    {
        return 0;
    }
    if (dp[n][m][k]!=-1)
    {
        return dp[n][m][k];
    }
    
    if (s1[n-1] == s2[m-1])
    {
        return dp[n][m][k] = 1+lcsink(n-1,m-1,k);
    }
    if(k)
    {
        return dp[n][m][k] = 1+lcsink(n-1,m-1,k-1);
    }
    return dp[n][m][k] = max(lcsink(n-1,m,k),lcsink(n,m-1,k));
}

signed main()
{
    memset(dp,-1,sizeof(dp));
    int n,m,k;
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    cin>>s1>>s2;
    cout<<lcsink(n,m,k)<<endl;
}