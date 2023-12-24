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
vector<int> parent(N);
vector<int>dis(N,mod);
vb vis(N,false);
vvi adj[N];
int n,m;


signed main()
{
    cin>>n>>m;
    rep(i,0,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({u,w});
        adj[v].push_back({v,w});
    }
    int source = 0;
    cin>>source;
    dis[source] = 0;
    set<pair<int,int> >s;
    s.insert({0,source});
    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x.second] = true;
        for(auto it:adj[x.second])
        {
            if (dis[it[0]] > dis[x.second]+it[1])
            {
                s.erase({dis[it[0]],it[0]});
                dis[it[0]] = dis[x.second]+it[1];
                s.insert({dis[it[0]],it[0]});
            }
            vis[it[0]] = true;
        }
    }
    rep(i,0,n)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}