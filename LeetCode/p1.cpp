//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define rep(i,j,k) for(int i =j;i<k;i++)
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[])
    {
        vector<vector<int>> a;
        rep(i,0,n)
        {
            a.push_back({price[i],i+1});
        }
        sort(a.begin(),a.end());
        int cnt = 0;
        for(auto it:a)
        {
            int c = k/it[0];
            int d = min(c,it[1]);
            cnt+=d;
            k-=(it[0]*d);
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends