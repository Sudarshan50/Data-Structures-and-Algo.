#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 100000007;
const int N = 1e4+2;
vi totient(N);




signed main()
{
    rep(i,0,N)
    {
        totient[i] = i;
    }
    rep(i,2,N)
    {
        if (totient[i] == i)
        {
            for(int j = 2*i;j<N;j+=i)
            {
                totient[j] *= i-1;
                totient[j] /= i;
            }
            totient[i] = i-1;
        }
    }
    rep(i,2,11)
    {
        cout<<totient[i]<<" ";
    }
    cout<<endl;
}