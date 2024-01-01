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

triplet extendedgcd(int a,int b)
{
    if(b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y =0;
        ans.gcd = a;
        return ans;
    }
    triplet smallans = extendedgcd(b,a%b);
    triplet ans;
    ans.x = smallans.y;
    ans.y = smallans.x - (a/b)*smallans.y;
    ans.gcd = smallans.gcd;
    return ans;
}

signed main()
{
    int n1,n2;cin>>n1>>n2;
    triplet ans =  extendedgcd(n1,n2);
    cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;
}