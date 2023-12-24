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
vector<int>size(N);


void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void dsu(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a!=b)
    {
        if (size[a]<size[b])
        {
            swap(a,b);
        }
        parent[b] =a;
        size[a]+=size[b];
    }
}


signed main()
{
    int n,m;cin>>n>>m;
    vvi adj;
    rep(i,0,N)
    {
        make_set(i);
    }
    rep(i,0,m)
    {
        int w,x,y;
        cin>>x>>y>>w;
        adj.push_back({w,x,y});
    }
    sort(adj.begin(),adj.end());
    int cost = 0;
    for(auto it:adj)
    {
        
        int w = it[0];
        int x = it[1];
        int y = it[2];
        int u =find_set(x);
        int v =find_set(y);
        if (u==v)
        {
            continue;
        }
        if (u != v)
        {
            cout<<x<<" "<<y<<" "<<endl;
            cost+=w;
            dsu(x,y);
        }
    }
    cout<<cost<<endl;
}
