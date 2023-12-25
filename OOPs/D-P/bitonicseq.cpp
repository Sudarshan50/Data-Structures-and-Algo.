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
vi dp(N,0);


signed main()
{
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    vi forward(n,1);
    vi backward(n,1);
    int ans = 0;
    rep(i,0,n)
    {
        rep(j,0,i)
        {
            if(a[i]>a[j])
                forward[i] = max(forward[i],1+forward[j]);
        }
    }
    for(int i = n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[i]>a[j])
                backward[i] = max(backward[i],1+backward[j]);
        }
    }
    rep(i,0,n)
    {
        ans = max(ans,forward[i]+backward[i]-1);
    }
    cout<<ans<<endl;
}