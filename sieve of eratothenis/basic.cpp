#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
const int N = 1e5+2;

void primesieve(int n)
{
    vi prime(N,0);
    rep(i,2,n+1)
    {
        if (prime[i] == 0)
        {
            for(int j =i*i;j<=n;j+=i)
            {
                prime[j] = 1;
            }
        }
    }
    rep(i,2,n)
    {
        if (prime[i] == 0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;

}

signed main()
{
    int n;
    cin>>n;
    primesieve(n);
}