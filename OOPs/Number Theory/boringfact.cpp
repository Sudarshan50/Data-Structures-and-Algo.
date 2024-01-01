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

int power(int a,int b,int p)
{
    int res = 1;
    a = a%p;
    while (b>0)
    {
        if(b&1)
        {
            res = (res*a)%mod;
        }
        a =(a*a)%mod;
        b = b>>1;
    }
    return res;
}

int modinverse(int a,int p)
{
    return power(a,p-2,p);
}

int boringfact(int n,int p)
{
    if(p<=n)
    {
        return 0;
    }
    int res = p-1;
    rep(i,n+1,p)
    {
        res = (res*modinverse(i,p))%p;
    }
    return res;
}

signed main()
{

        int n,p;cin>>n>>p;
        cout<<boringfact(n,p)<<endl;

}