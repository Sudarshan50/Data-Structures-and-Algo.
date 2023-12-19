#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

//Getting bit of desired location..
int getBit(int n,int pos)
{
    return((n & 1<<pos)!=0); // // operator sifts 1 to left by pos times and then ands it with n.
}
//Set bit mean s inserting 1 at desired location.
//Unset bit or clear bit means inserting 0 at desired location.
int setBit(int n,int pos)
{
    return((n | 1<<pos)); // // operator sifts 1 to left by pos times and then ands it with n.
}
int clearBit(int n,int pos)
{
    int mask = ~(1<<pos);
    return((n & mask));
}
//First clear the bit and then set the bit with the desired bit using setbit....
int updateBit(int n,int pos,int val)
{
    int mask = ~(1<<pos);
    int clearbit = n&mask;
    int setbit = clearbit|(val<<pos);
    return setbit; 
}


signed main()
{
    int n,i;
    cin>>n>>i;
    // int c = getBit(n,i);
    // cout<<c<<endl;
    // cout<<setBit(n,i)<<endl;
    // cout<<clearBit(n,i)<<endl;
    cout<<updateBit(n,i,1)<<endl;
}


