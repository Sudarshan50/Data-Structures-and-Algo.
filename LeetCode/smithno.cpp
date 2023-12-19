//{ Driver Code Starts

#include <iostream>
#define int long long int
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int smithNum(int n) 
    {
        int m =n;
        vector<int> pfactor;
        vector<int> p(n);
        for(int i =2;i<=n;i++)
        {
            p[i] = i;
        }
        for(int i =2;i<=n;i++)
        {
            if(p[i] == i)
            {    for(int j =i*i;j<=n;j+=i)
                {
                    if(p[j] == j )
                    {
                        p[j] = i; 
                    }
                }
            }
        }
        while(n!=1)
        {
            pfactor.push_back(p[n]);
            n/=p[n];
        }
        unordered_map<int,int> track;
        for(int i = 0;i<pfactor.size();i++)
        {
            track[pfactor[i]]++;
        }
        int checker = 0;
        unordered_map<int,int> :: iterator it;
        for(it = track.begin();it!=track.end();it++)
        {
            checker+=(it->first * it->second);
        }
        int sod = 0;
        while(m>0)
        {
            sod+=(m%10);
            m/=10;
        }
        if (checker == sod)
        {
            return 1;
        }
        else    
            return 0;
        
    }
};

//{ Driver Code Starts.
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends