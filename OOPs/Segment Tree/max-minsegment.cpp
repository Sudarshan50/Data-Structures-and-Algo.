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
vi segtree(4*N);
vi a(N);



void update(int node,int start,int end,int val,int idx)
{
    if (start == end)
    {
        a[start] = val;
        segtree[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if (idx<=mid)
    {
        update(2*node,start,mid,val,idx);
    }
    else
    {
        update(2*node+1,mid+1,end,val,idx);
    }
    segtree[node] = max(segtree[2*node],segtree[2*node+1]);
}

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
    segtree[node] = max(segtree[2*node],segtree[2*node+1]);
}

int query(int node,int start,int end,int l,int r)
{
    if(start>r || end<l)
    {
        return INT_MIN;
    }
    if(l<=start && end<=r)
    {
        return segtree[node];
    }
    int mid = (start+end)/2;
    int q1 = query(node*2,start,mid,l,r);
    int q2 = query(node*2+1,mid+1,end,l,r);
    return max(q1,q2);
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
        if(q == 1)
        {
            int l,r;
            cin>>l>>r;
            int ans = query(1,0,n-1,l,r);
            cout<<ans<<endl;
        }
        if(q==2)
        {
            int idx,val;
            cin>>idx>>val;
            update(1,0,n-1,val,idx);
            cout<<query(1,0,n-1,0,n-1)<<endl;
        }
        if (q== -1)
        {
            break;
        }
        
    }   
    // rep(i,0,n)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // rep(i,0,16)
    // {
    //     cout<<segtree[i]<<" ";
    // }
    // cout<<endl;
    
}



