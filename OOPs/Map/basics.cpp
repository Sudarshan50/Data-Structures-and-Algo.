#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>

const int N = 1e5+2;
vi adj[N];

signed main()
{
    int n,m;
    cin>>n>>m;
    vvi adj(n+1,vi(n+1,0));
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    rep(i,1,n+1)
    {
        rep(j,1,n+1)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    cin>>n>>m;
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i,0,n)
    {
        vi :: iterator it;
        for(it = adj[i].begin();it!=adj.[i].end();it++)
        {
            cout<< *it<<" ";
        }
        cout<<endl;
    }
}
