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

int query(int node,int start,int end,int l,int r)
{
    if(start>r || end<l)
    {
        return 0;
    }
    if(l<=start && end<=r)
    {
        return segtree[node];
    }
    int mid = (start+end)/2;
    int q1 = query(node*2,start,mid,l,r);
    int q2 = query(node*2+1,mid+1,end,l,r);
    return q1+q2;
}


signed main()
{
    int n;cin>>n;
    rep(i,0,n)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    while (1)
    {
        int q;cin>>q;
        if(q == -1)
        {
            break;
        }
        if (q == 1)
        {
            int l,r;cin>>l>>r;
            int ans = query(1,0,n-1,l,r);
            cout<<ans<<" ";
        }
    }
    cout<<endl;
}