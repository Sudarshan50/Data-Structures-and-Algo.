#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9+7;
const int N = 1e4+2;
#define mk unordered_map<int,int>
vector<int> parent(N);
vi curr(N,0);

signed main()
{
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    int curr=0,maxsm=INT_MIN;
    rep(i,0,n)
    {
        if (curr<0)
        {
            curr = 0;
        }
        curr += a[i];
        maxsm = max(maxsm,curr);
    }
    cout<<maxsm<<endl;
}