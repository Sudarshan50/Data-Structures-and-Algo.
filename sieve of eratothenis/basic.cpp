#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

void primesieve(int n)
{
    vi prime(n,0);
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
            // prime[i] = i;
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