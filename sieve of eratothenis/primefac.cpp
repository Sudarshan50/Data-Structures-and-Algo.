#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

void primefact(int n)
{
    vi spf(n);
    rep(i,2,n+1)
    {
        spf[i] = i;
    }
    rep(i,2,n+1)
    {
        if (spf[i] == i)
        {
            for(int j = i*i;j<=n;j+=i)
            {
                if (spf[j] == j)
                {
                    spf[j] =i;
                }
            }
        }
    }
    while (n!=1)
    {
        cout<<spf[n]<<endl;
        n/=spf[n];
    }
    
}

signed main()
{
    int n;
    cin>>n;
    primefact(n);

}