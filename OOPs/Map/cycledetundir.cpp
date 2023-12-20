#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define vb vector<bool>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
const int mod = 1e9+7;
const int N = 1e5+2;


bool iscycle(int src,vvi &adj,vb &vis,vi &stack)
{
    stack[src] = true;
    if (!vis[src])
    {
        vis[src] = true;
        for(auto it:adj[src])
        {
            if (!vis[it] and iscycle(it,adj,vis,stack))
            {
                return true;
            }
            if(stack[it])
            {
                return true;
            }
        }
    }
    stack[src] = false;
    return false;
}

signed main()
{
    int n,m;
    cin>>n>>m;
    vvi adj(n);
    vb vis (n,false);
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    bool cycle =false;
    vi stack(n);
    rep(i,0,n)
    {
        if (!vis[i] and iscycle(i,adj,vis,stack))
        {
            cycle = true;
        }
    }
    cout<<cycle<<endl;
}