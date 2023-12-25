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
vi dp(N,-1);

int posspair(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    if (n<0)
    {
        return 0;
    }
    if (dp[n]!=-1)
    {
        return dp[n];
    }
    else
        dp[n] = posspair(n-1)+(n-1)*posspair(n-2);

    return dp[n]%mod;
}

signed main()
{
    int n;
    cin>>n;
    cout<<posspair(n)<<endl;
}