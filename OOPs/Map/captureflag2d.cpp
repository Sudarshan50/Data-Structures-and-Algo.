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
#define mk unordered_map<int,int>
vector<int> parent(N);
vb vis(N,false);

void change(vector<vector<char>> &a,int x,int y)
{
    a[x][y] = '*';
    int dpx[] = {0,0,1,-1};
    int dpy[] = {1,-1,0,0};
    rep(i,0,4)
    {
        int cx = x+dpx[i];
        int cy = y+dpy[i];
        if (cx>=0 && cx<a.size() && cy>=0 && cy<a[0].size())
        {
            change(a,cx,cy);
        }
    }
}


signed main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char> > qu(n,vector<char>(m));
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cin>>qu[i][j];
        }
    }
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if (i == 0 || i==n-1 || j == 0|| j==m-1)
            {
                if (qu[i][j] == 'O')
                {
                    change(qu,i,j);
                }
            }
            
        }
    }
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(qu[i][j] == 'O')
            {
                qu[i][j] = 'X';
            }
        }
    }
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(qu[i][j] == '*')
            {
                qu[i][j] = 'O';
            }
        }
    }
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cout<<qu[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}