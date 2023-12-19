#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>


void getbit(int n)
{
    int i =0;
    int ans = 0;
    while (n)
    {
        int bit = n & 1;
        cout<<bit<<endl;
        ans = bit*(pow(10,i))+ans;
        i++;
        n=n>>1;
    }
    cout<<ans<<endl;
}

signed main()
{
    int n;
    cin>>n;
    getbit(n);
}