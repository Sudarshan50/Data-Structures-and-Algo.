#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

bool isPowerofTwo(int n)
{
    return(n&& !(n& n-1));
}
signed main()
{
    int n;
    cin>>n;
    // One case is still remaning that is when n == 0;
    // (n & n-1)==0?cout<<"YES"<<endl:cout<<"NO"<<endl;

    cout<<isPowerofTwo(n)<<endl;

}