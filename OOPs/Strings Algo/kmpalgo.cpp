#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 100000007;
const int N = 1e5+2;
int p =31;
vi power(N);

vi prefix_function(string &sh,int n)
{
    vi pref(n,0);
    rep(i,1,n)
    {
        int j = pref[i-1];
        while (j and sh[i]!=sh[j])
        {
            j = pref[j-1];
        }
        if(sh[i] == sh[j])
        {
            j++;
        }
        pref[i] = j;
    }
    return pref;
}

signed main()
{
    // string sh = "abcabcd";
    // int n = sh.size();
    // vi ans = prefix_function(sh,n);
    // for(auto it:ans)
    // {
    //     cout<<it<<" ";
    // }
    string sh = "geeks";
    int n = sh.size();
    vi ans = prefix_function(sh,n);
    string t = "geeksforgeeks";
    vi pos;
    int i(0),j(0);
    while (i<t.size())
    {
        if (t[i] == sh[j])
        {
            i++;j++;
        }
        else
            if (j)
            {
                j = ans[j-1];
            }
            else
                i++;

        if (j == n)
        {
            pos.push_back(i-n);
        }
    }
    for(auto it:pos)
    {
        cout<<it<<" ";
    }
    cout<<endl;   
}