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


signed main()
{
    string sh;
    cin>>sh;
    int it = 0;
    for(auto i:sh)
    {
        it^=i;
    }
    // 
    cout<<it<<endl;
}