#include<iostream>
using namespace std;
#include<map>
#include<math.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<unordered_map>
#define rep(i,j,k) for (int i = j; i <k;i++)
#define ff first
#define ss second
#define mk map<int,int>
#define mp unordered_map<int,int>
#define iter map<int,int>::iterator
#define itep unordered_map<int,int>::iterator
#define in(n) cin>>n
#define out(n) cout<<n
#define vi vector<int>
#define vii vector<int,int>
#define int long long int


signed main()
{
    string str = "abcdefghijklmnopqrstuvWxyz";
    //Uppercase ans lowercase;
    rep(i,0,str.size())
    {
        str[i]>='a' && str[i]<='z' ? str[i]-=32:str[i]+=32;
    }
    cout<<str<<endl;
    return(0);

}