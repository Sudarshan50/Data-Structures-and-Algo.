#include<iostream>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define br cout<<endl
#define ll left 
#define rr right

int findfeasible(int arr[],int n,int min)
{
    int sum = 0,painter = 1;
    rep(i,0,n)
    {
        sum+=arr[i];
        if (sum>min)
        {
            sum = arr[i];
            painter++;
        }
    }
    return painter;
}


int painterpartion(int arr[],int n,int m)
{
    int sum = 0,k= 0;
    rep(i,0,n)
    {
        k = max(k,arr[i]);
        sum+=arr[i];
    }
    int low = k;int high = sum;
    while (low<high)
    {
        int mid = (low+high)/2;
        int painter = findfeasible(arr,n,mid);
        if (painter <= m)
        {
            high = mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}

signed main()
{
    int arr[] = {10,20,30,40};
    int n = 4;
    int m =2;
    cout<<painterpartion(arr,n,m)<<endl;
}