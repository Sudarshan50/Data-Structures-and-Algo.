#include<iostream>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define br cout<<endl
#define ll left 
#define rr right

bool ispossible(int arr[],int m,int n,int min)
{
    int studentreq = 1;int sum = 0;
    rep(i,0,n)
    {
        if (arr[i]>min)
        {
            return false;
        }
        if (sum+arr[i]> min)
        {
            studentreq++;
            sum = arr[i];
            if (studentreq > m)
            {
                return false;
            }
        }
        else
        {
            sum+=arr[i];
        }
    }
    return true;
}
int minmaxpages(int arr[],int m,int n)
{
    if (m>n)
    {
        return -1;
    }
    int sum = 0;
    rep(i,0,n)
    {
        sum+=arr[i];
    }
    int start = 0;
    int end = sum;
    int ans = INT_MAX;
    while (start<end)
    {   
        int mid = (start+end)/2;
        if (ispossible(arr,m,n,mid))
        {
            ans = min(ans,mid);
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return ans;
}

signed main()
{
    int arr[] = {12,34,67,90};
    int n = 4;
    int m =2;
    cout<<minmaxpages(arr,m,n)<<endl;
}