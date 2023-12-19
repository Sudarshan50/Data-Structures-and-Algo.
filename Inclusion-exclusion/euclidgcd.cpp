#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

int gcd(int a,int b)
{
   while (a!=0)
   {
        int rem = a%b;
        a=b;
        b=rem;
   }
   return b;
}

signed main()
{
    cout<<gcd(42,24)<<endl;
}