#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
const int mod = 1e9+7;
const int N = 1e5+2;


signed main()
{
    int n,m;
    cin>>n>>m;
    vvi adj(n);
    vi in_degree(n,0);
    rep(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        in_degree[v]++;
    }
    queue<int>q;
    rep(i,0,n)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it : adj[node])
        {
            in_degree[it]--;
            if (in_degree[it]== 0)
            {
                q.push(it);
            }
        }
    }
}