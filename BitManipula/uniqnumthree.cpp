#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

int getbit(int n,int pos)
{
    return ((n & 1<<pos)!=0);
}
int setbit(int n,int pos)
{
    return (n | 1<<pos);
}



void uniqnum(vi &a,int n)
{
    int result = 0;
    rep(i,0,64)
    {   
        int sum = 0;
        rep(j,0,n)
        {    
            if (getbit(a[j],i))
            {
                sum++;
            }
        }
        if (sum%3 != 0)
        {
            result = setbit(result,i);
        }
    }
    cout<<result<<endl;
}

signed main()
{
      vi a(10);
      rep(i,0,10)
      {
        cin>>a[i];
      }
    uniqnum(a,10);

}