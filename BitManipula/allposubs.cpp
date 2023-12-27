#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<char>

void possub(vi &a,int n)
{
    rep(i,0,1<<n)
    {
        rep(j,0,n)
        {
            if (i& (1<<j))
            {
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
    }
}

signed main()
{
    vi pig(3);
    pig[0] = 'a';pig[1] = 'b';pig[2] = 'c';
    possub(pig,3);
}