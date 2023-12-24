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

signed main()
{
    vvi graph = {
    }
    int n=graph.size();
    vvi dis = graph;
    rep(k,0,n)
    {
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                if (dis[i][k]+dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
            }
        }
    }
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            if (dis[i][j] == mod)
            {
                cout<<"INF"<<" ";
            }
            else
                cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}