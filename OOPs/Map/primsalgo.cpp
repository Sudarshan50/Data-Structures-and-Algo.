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
vector<int>dis(N);
vb vis(N,false);
vvi adj[N];
int cost = 0;
int n,m;


    
void primsMST(int source)
{
    rep(i,0,n)
    {
        dis[i] = mod;
    }
    set<vi>a;
    dis[source] = 0;
    a.insert({0,source});
    while (!a.empty())
    {
        auto x = *a.begin();
        a.erase(x);
        vis[x[1]] = 1;
        cost+=x[0];
        for(auto it:adj[x[1]])
        {
            if (vis[it[0]])
            {
                continue;
            }
            if(dis[it[0]] > it[1])
            {
                a.erase({dis[it[0]],it[0]});
                dis[it[0]] = it[1];
                a.insert({dis[it[0]],it[0]});
            }
        }
    }

}

signed main()
{
    cin>>n>>m;
    rep(i,0,m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    primsMST(0);
    cout<<cost<<endl;
}
