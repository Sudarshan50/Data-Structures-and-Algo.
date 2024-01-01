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


class triplet
{
    public:
    int x,y,gcd;
};


triplet moduloinverse(int a,int m)
{
    if(m == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    triplet smallans = moduloinverse(m,a%m);
    triplet ans;
    ans.x = smallans.y;
    ans.y = smallans.x-(a/m)*smallans.y;
    ans.gcd = smallans.gcd;
    return ans;
}
signed main()
{
    int a,m;cin>>a>>m;
    triplet ans = moduloinverse(a,m);
    if(ans.x<0)
    {
        int temp = (ans.x*a)%m;
        cout<<abs(temp)+m<<endl;
    }
    else
        cout<<ans.x<<endl;
    
}