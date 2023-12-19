#include<iostream>
using namespace std;
#include<map>
#define ff first
#define ss second
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

signed main()
{
    vi a(5);
    rep(i,0,5)
    {
        cin>>a[i];
    }
    //Appraoch- 01 // By hashing...

    // map<int,int> fk;
    // rep(i,0,5)
    // {
    //     fk[a[i]]++;
    // }
    // map<int,int>::iterator it;
    // for(it = fk.begin();it!=fk.end();it++)
    // {
    //     if (it->ss == 1 )
    //     {
    //         cout<<it->ff<<endl;
    //         break;
    //     }
    // }

    //Appraoch - 02 // By using XOR operator...
    int xorsum = 0;
    rep(i,0,5)
    {
        xorsum = xorsum^a[i];
    }
    cout<<xorsum<<endl;
}