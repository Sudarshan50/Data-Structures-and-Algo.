#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9+7;
const int N = 1e5+2;




int get_comp(int idx,vvi &adj,vb &vis)
{
    if (vis[idx])
    {
        return 0;
    }
    vis[idx] = true;
    int ans = 1;
    for(auto it:adj[idx])
    {
        if (!vis[it])
        {
            ans+= get_comp(it,adj,vis);
            vis[it] = true;
        }
    }
    return ans;
}
signed main()
{
    int n,m;
    cin>>n>>m;
    vvi adj(n);
    vb vis(n,0);
    rep(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vi comp;
    rep(i,0,n)
    {
        if (!vis[i])
        {
            comp.push_back(get_comp(i,adj,vis));
        }
    }
    int ans = 0;

    for(auto i:comp)
    {
        ans+= i*(n-i);
    }
    ans/=2;
    cout<<ans<<endl;
}