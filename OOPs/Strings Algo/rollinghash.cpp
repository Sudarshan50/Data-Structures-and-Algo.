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

int isunique(string &sh)
{
    int n = sh.size();
    int hash = 0;
    rep(i,0,sh.size())
    {
        hash = (hash+(sh[i] -'a' +1)*power[i])%mod;
    }
    return hash;
}

signed main()
{
    power[0]= 1;
    rep(i,1,N)
    {
        power[i] = (power[i-1]*p)%mod;
    }
    vector<string> sh= {"aa","ab","aa","b","aa","cc"};
    vi hash;
    for(auto it:sh)
    {
        hash.push_back(isunique(it));
    }
    int count = 0;
    sort(hash.begin(),hash.end());
    rep(i,0,hash.size())
    {
        if (i == 0 or hash[i] != hash[i-1])
        {
            count++;
        }
    }
    cout<<count<<endl;

}