#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 100000007;
const int N = 1e5+2;
int p =31;
vi power(N);

signed main()
{
    power[0]= 1;
    rep(i,1,N)
    {
        power[i] = (power[i-1]*p)%mod;
    }
    string sh = "bat";
    string t = "batmanandrobinarebat";
    int n = sh.size();int m = t.size();
    int hash_sh = 0;
    rep(i,0,n)
    {
        hash_sh = (hash_sh+(sh[i] - 'a' +1)*power[i])%mod;
    }
    vi hash_t(m+1,0);
    rep(i,0,m)
    {
        hash_t[i+1] = (hash_t[i]+(t[i] - 'a' +1)*power[i])%mod;
    }

    for(int i = 0;(i+n-1)<m;i++)
    {
        int curr_hash = (hash_t[i+n] - hash_t[i]+mod)%mod;
        if (curr_hash == (hash_sh*power[i])%mod)
        {
            cout<<i<<" ";
        }
        // cout<<"foo"<<" ";
    }
    cout<<endl;
}