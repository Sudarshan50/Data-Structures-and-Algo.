#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
const int mod = 1e9+7;
const int N = 1e5+2;
vi adj[N];
bool vis[N];

void dfs(int node)
{
    //inorder..
    vis[node] = 1;
    cout<<node<<" ";
    vi :: iterator it;
    for(it = adj[node].begin();it!= adj[node].end();it++)
    {
        if (!vis[*it])
        {
            dfs(*it);
        }
    }   
}
void dfspostor(int node)
{
    //portorder...
    vis[node] = 1;
    vi :: iterator it;
    for(it = adj[node].begin();it!= adj[node].end();it++)
    {
        if (!vis[*it])
        {
            dfspostor(*it);
        }
    }   
    cout<<node<<" ";
}

signed main()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,n)
    {
        vis[i] = false;
    }
    int x,y;
    rep(i,0,n)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfspostor(1);
    cout<<endl;
    dfs(1);
    cout<<endl;
}