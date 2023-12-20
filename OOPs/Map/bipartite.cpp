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
bool check = true;

void color(int idx,int col,vb &vis,vi &colcheck,vvi &adj)
{
    if (colcheck[idx]!= -1 && colcheck[idx]!= col)
    {
        check = false;
        return;
    }
    colcheck[idx] = col;
    if (vis[idx])
    {
        return;
    }
    vis[idx] = true;
    for(auto it: adj[idx])
    {
        color(it,(col ^ 1),vis,colcheck,adj);
    }
}

signed main()
{
    int n,m;
    cin>>n>>m;
    vvi adj(n);
    vb vis(n,false);
    rep(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi colcheck(N,-1);
    rep(i,0,n)
    {   
        if (!vis[i])
        {
            color(i,0,vis,colcheck,adj);
        }
    }
    cout<<check<<endl;


}