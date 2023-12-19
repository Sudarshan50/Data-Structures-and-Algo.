#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

int onecalc(int n)
{
    int ctr = 0;
    while (n)
    {
        n = n&(n-1);
        ctr++;
    }
    return ctr;
    
}

signed main()
{
    int n;
    cin >> n;
    cout<<onecalc(n)<<endl;

}