#include<iostream>
#include<map>
#define rep(i,p,n) for(int i =p ; i <n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define mk map<int,int>
using namespace std;

signed main()
{
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    mk(fk);
    int perfixSum = 0;
    rep(i,0,n)
    {
        perfixSum += a[i];
        fk[perfixSum]++;
    }
    int ans  = 0;
    mk :: iterator it;
    for(it = fk.begin(); it != fk.end();it++)
    {
        int c = it->ss;
        ans += c*(c-1)/2;
        if (it->ff == 0)
        {
            ans+=it->ss;
        }
    }
    cout<<ans<<endl;
    return(0);
}