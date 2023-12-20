#include<bits/stdc++.h>
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


signed main()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,N)
    {
        vis[i] = 0;
    }
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    cout<<endl;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        vi :: iterator it;
        for(it = adj[temp].begin();it!=adj[temp].end();it++)
        {
            if (!vis[*it])
            {
                vis[*it] = true;
                q.push(*it); 
            }
        }
    }
    cout<<endl;
}