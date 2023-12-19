#include<iostream>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define br cout<<endl
#define ll left 
#define rr right


int peakelem(int arr[],int n,int start,int end)
{
    if (start>end)
    {
        return -1;
    }
    int mid = start+((end-start)/2);
    if (mid == 0 || arr[mid-1]<=arr[mid] &&(mid==n-1 || arr[mid]>= arr[mid+1]))
    {
        return mid;
    }
    if (mid && arr[mid] > arr[mid-1])
    {
        return peakelem(arr,n,mid+1,end);
    }
    else
        return peakelem(arr,n,start,mid-1);
}

signed main()
{
    int arr[] = {0,6,8,5,7,9};
    int n= 6;
    cout<<peakelem(arr,n,0,n-1)<<endl;
}