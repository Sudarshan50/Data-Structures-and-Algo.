#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

 bool primesieve(int n)
{
    int m = n;
    bool see = false;
    vector<int> prime(n,0);
    for(int i =2;i<=n;i++)
    {
        if (prime[i] == 0)
        {
            for(int j =i*i;j<=n;j+=i)
            {
                prime[j] = 1;
            }
        }
        if (prime[i] == 0 && i == n)
        {
            see = true;
        }
    }
    return see;
}

signed main()
{
    // 
    cout<<primesieve(5);
}