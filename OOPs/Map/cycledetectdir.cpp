#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
const int mod = 1e9+7;
const int N = 1e5+2;

bool iscycle(int src,vvi &adj,vector<bool> &vis,int parent)
{
    vis[src] = true;
    for(auto it :adj[src])
    {
        if(it !=parent)
        {
            if (vis[it])
            {
                return true;
            }
            if (!vis[it] and iscycle(it,adj,vis,src))
            {
                return true;
            }
        }        
    }
    return false;
}

signed main()
{
    int n,m;
    cin>>n>>m;
    vvi adj(n);
    vector<bool> vis (n,false);
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle = false;
    rep(i,0,n)
    {
        if (!vis[i] and iscycle(i,adj,vis,-1))
        {
            cycle = true;
        }
    }
    cout<<cycle<<endl;
}