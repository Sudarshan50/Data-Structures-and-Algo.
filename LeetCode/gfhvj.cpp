
#include<bits/stdc++.h>
using namespace std;


#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<long long>
unordered_map<int,int> mk;
class Solution {
public:
    void primesieve(int x)
    {
        vi cont(2e5+2);
        rep(i,2,x+1)
        {
            cont[i] = i;
        }
        rep(i,2,x+1)
        {
            if(cont[i] == i)
            {
                for(int j = i*i;i<=x;j+=i)
                {
                    if(cont[j] == j)
                    {
                        cont[j] = i;
                    }
                }
            }
        }
        while(x!=1)
        {
            mk[x]++;
            x/=cont[x];
        }
    }
	int sumOfPowers(int a, int b)
	{
	    rep(i,a,b+1)
	    {
	        primesieve(i);
	    }
	    int ans = 0;
	    for(auto &it:mk)
	    {
	        ans+=it.second;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends