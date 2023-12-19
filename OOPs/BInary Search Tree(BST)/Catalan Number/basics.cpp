#include<iostream>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define br cout<<endl
#define ll left 
#define rr right

int catalan(int n)
{
    if (n<=1)
    {
        return 1;
    }
    int res = 0;
    rep(i,0,n)
    {
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}
signed main()
{
    rep(i,0,6)
    {
        cout<<catalan(i)<<" ";
    }
    br;
}