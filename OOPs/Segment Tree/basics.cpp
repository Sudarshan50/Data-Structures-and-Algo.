#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9 + 7;
const int N = 1e4+2;
#define int long long int
vi segtree(4*N,0);
vi a(N);


void build(int node,int start,int end)
{
    if(start == end)
    {
        segtree[node] = a[start];
        return;
    }
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    segtree[node] = segtree[2*node]+segtree[2*node+1];
}


signed main()
{
    int n;cin>>n;
    rep(i,0,n)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    rep(i,1,15)
    {
        cout<<segtree[i]<<" ";
    }
    cout<<endl;
}