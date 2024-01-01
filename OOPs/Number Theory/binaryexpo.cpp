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
vi totient(N);
#define int long long int

int poweriter(int a,int b)
{
    a%=mod;
    if(b == 0)
    {
        return 1;
    }
    int nby2 = pow(a,b/2);
    nby2%=mod;
    if(b&1)
    {
        return (((nby2*nby2)%mod)*a)%mod;
    }
    else
        return (nby2*nby2)%mod;
}


int powerec(int a,int n)
{
    a%=mod;
    int ans = 1;
    while (n>0)
    {
        if(n&1)
        {
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        n=n>>1;
    }
    return ans;
    
}


signed main()
{
    int a,b;cin>>a>>b;
    // cout<<poweriter(a,b)<<endl;
    cout<<powerec(a,b)<<endl;
}