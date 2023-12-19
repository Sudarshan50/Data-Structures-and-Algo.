#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

int SetBit(int n,int pos)
{
    return ((n & 1<<pos)!=0);
}
 
void uniqnum(vi &a,int n)
{
    int xorsum = 0;
    rep(i,0,n)
    {
        xorsum = xorsum ^ a[i];
    }
    int tempxorsum = xorsum;
    int pos = 0;
    int setbit = 0;
    while (setbit!=1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1; // To change the position 
                            //of the bit becasue we have already checked 
                             //the last position. 
    }
    int newxorsum = 0;
    rep(i,0,n)
    {
        if (SetBit(a[i],pos-1))
        {
            newxorsum = xorsum^a[i];
        }
    }
    cout<<newxorsum<<endl;
    cout<<(newxorsum ^ tempxorsum)<<endl;
}

signed main()
{
    vi a(8);
    rep(i,0,8)
    {
        cin>>a[i];
    }
    uniqnum(a,8);
}