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
    string s = "apna collgena";
    string t = "na";
    int p = s.size();int q = t.size();
    rep(i,0,(p-q+1))
    {
        if (s.substr(i,q) == t)
        {
            cout<<i<<endl;
        }
    }

}