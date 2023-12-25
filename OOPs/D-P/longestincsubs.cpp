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
vi dp(N,-1);


//Memotization..... -- Wrong ans in case of "10 10 9 8 4 8 10 4 5 12 12 7".....
// int longestsubs(vi &a,int n)
// {
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     dp[n]= 1;
//     rep(i,0,n)
//     {
//         if (a[n]>a[i])
//         {
//             dp[n] = max(dp[n],1+longestsubs(a,i));
//         }
//     }
//     return dp[n];
// }


signed main()
{
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    // cout<<longestsubs(a,n-1)<<endl;
    dp[0] =1;
    int ans = 0;
    rep(i,1,n)
    {
        rep(j,0,i)
        {
            if (a[i]> a[j])
            {
                dp[i] = max(dp[i],1+dp[j]); // Tabulation Appraoch....
            }
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
}