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

vvi multiply(vvi &a,vvi &b)
{
    int n = a.size();
    vvi ans(n,vi (n,0));
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            rep(k,0,n)
            {
                ans[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}


vvi matrixexpon(vvi &a,int n)
{
    if(n==0)
    {
        vvi temp = {{1,1},{1,1}};
        return temp;
    }
    if (n ==1)
    {
        return a;
    }
    
    vvi halfpow = matrixexpon(a,n/2);
    vvi temp = multiply(halfpow,halfpow);
    if(n&1)
    {
        temp = multiply(temp,a);
    }
    return temp;
}

signed main()
{
    int n;cin>>n;
    vvi temp = {{1,1},{1,0}};
    vvi ans = matrixexpon(temp,n);
    // rep(i,0,ans.size())
    // {
    //     rep(j,0,ans.size())
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans[0][1]<<endl;
}
//1 1 2 3 5 8 13 