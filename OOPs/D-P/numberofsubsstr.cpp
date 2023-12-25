#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9+7;
const int N = 1e2+2;
#define mk unordered_map<int,int>
vector<int> parent(N);
vi a(N);
vvi dp(N,vi (N,-1));



signed main()
{
    int n;cin>>n;
    string s;
    cin>>s;
    int e =1,a=0,ab=0,abc = 0;
    for(auto i:s)
    {
        if (i=='a')
        {
            a+=e;
        }
        if (i == 'b')
        {
            ab+=a;
        }
        if (i == 'c')
        {
            abc+=ab;
        }
        if (i == '?')
        {
            abc = 3*abc +ab;
            ab = 3*ab + a;
            a = 3*a +e;
        }
    }
    cout<<abc<<endl;
}