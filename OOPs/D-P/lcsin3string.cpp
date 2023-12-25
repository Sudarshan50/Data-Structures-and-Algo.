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


int lcsin3(int n,int m,int k)
{
    if (n<=0 || m<=0 || k<=0)
    {
        return 0;
    }
    if (dp[n][m][k]!= -1)
    {
        return dp[n][m][k];
    }
    if (s1[n-1] == s2[m-1] and s2[m-1] == s3[k-1])
    {
        return dp[n][m][k] = 1+lcsin3(n-1,m-1,k-1);
    }
    else
    {
        int p = lcsin3(n-1,m,k);
        int q = lcsin3(n,m-1,k);
        int r = lcsin3(n,m,k-1);
        return dp[n][m][k]= max({p,q,r});
    }
}

signed main()
{
    int n,m,o;
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>o;
    cin>>s1>>s2>>s3;
    cout<<lcsin3(n,m,o)<<endl;
}