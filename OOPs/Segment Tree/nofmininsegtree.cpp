#include<bits/stdc++.h>
using namespace std;
#define fucku ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ff first
#define ss second
#define ll left 
#define rr right
#define pi pair<int,int>
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9 + 7;
const int N = 1e5+2;
#define int long long int
pi segtree[4*N];
vi a(N);



void update(int node,int start,int end,int val,int idx)
{
    if (start == end)
    {
        a[start] = val;
        segtree[node].ff = val;
        segtree[node].ss =1;
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
    if (segtree[2*node].ff<segtree[2*node+1].ff)
    {
        segtree[node]  = segtree[2*node];
    }
    else if (segtree[2*node].ff>segtree[2*node+1].ff)
    {
        segtree[node]  = segtree[2*node+1];
    }
    else
    {
        segtree[node].ff = segtree[2*node].ff;
        segtree[node].ss = segtree[2*node].ss+segtree[2*node+1].ss;
    }
}

void build(int node,int start,int end)
{
    if(start == end)
    {
        segtree[node].ff = a[start];
        segtree[node].ss = 1;
        return;
    }
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    if (segtree[2*node].ff<segtree[2*node+1].ff)
    {
        segtree[node]  = segtree[2*node];
    }
    else if (segtree[2*node].ff>segtree[2*node+1].ff)
    {
        segtree[node]  = segtree[2*node+1];
    }
    else
    {
        segtree[node].ff = segtree[2*node].ff;
        segtree[node].ss = segtree[2*node].ss+segtree[2*node+1].ss;
    }
    

}

pi query(int node,int start,int end,int l,int r)
{
    if(start>r || end<l)
    {
        return {mod,-1};
    }
    if(l<=start && end<=r)
    {
        return segtree[node];
    }
    pi ans;
    int mid = (start+end)/2;
    pi q1 = query(node*2,start,mid,l,r);
    pi q2 = query(node*2+1,mid+1,end,l,r);
    if(q1>q2)
    {
        ans = q2;
    }
    else if (q1<q2)
    {
        ans = q1;
    }
    else
    {
        ans.ff = q1.ff;
        ans.ss =q1.ss+q2.ss;

    }
    return ans;
}

signed main()
{
    fucku;
    int n,t;cin>>n>>t;
    rep(i,0,n)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    while (t--)
    {
        int q;cin>>q;
        if(q == 2)
        {
            int l,r;
            cin>>l>>r;
            pi ans = query(1,0,n-1,l,r-1);
            cout<<ans.ff<<" "<<ans.ss<<endl;
        }
        if(q==1)
        {
            int idx,val;
            cin>>idx>>val;
            update(1,0,n-1,val,idx);
        }        
    }   
}



