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
vb vis(N,false);
int n,m;
// vector<int>dis(n,mod);



signed main()
{
    cin>>n>>m;
    vvi adj;
    rep(i,0,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    vi dis(n,mod);
    int src;
    cin>>src;
    dis[src] = 0;
    rep(i,0,n-1)
    {
        for(auto it:adj)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dis[v] = min(dis[v],(dis[u]+w));  
        }
    }
    for(auto it:dis)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}