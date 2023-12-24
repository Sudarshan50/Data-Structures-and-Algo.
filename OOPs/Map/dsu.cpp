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

void makeset(vi &parent,int v,vi &size)
{
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v,vi &parent)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v],parent);
}
void dsu(int a,int b,vi &parent,vi &size)
{
    a = find_set(a,parent);
    b = find_set(b,parent);
    if (a!=b)
    {
        if(size[a]<size[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}


signed main()
{
    int n,m;
    cin>>n>>m;
    vi parent(N);
    vi size(N);
    vvi adj;
    rep(i,0,N)
    {
        makeset(parent,i,size);
    }
    bool cycle = false;
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adj.push_back({x,y});
    }

    for(auto it:adj)
    {
        int x = it[0];
        int y = it[1];
        int u = find_set(x,parent);
        int v = find_set(y,parent);
        if (u == v)
        {   
            cycle = true;
        }
        else
            dsu(x,y,parent,size);
    }
    cout<<cycle<<endl;
}
