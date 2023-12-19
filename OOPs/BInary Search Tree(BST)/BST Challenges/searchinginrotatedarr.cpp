#include<iostream>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define br cout<<endl
#define ll left 
#define rr right

int searchinrotarr(int arr[],int start,int end,int key)
{
    if (start>end)
    {
        return -1;
    }
    int mid = (start+end)/2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[start]<=arr[mid])
    {
        if (key>arr[start] && key<arr[mid])
        {
            return searchinrotarr(arr,start,mid-1,key);
        }
        return searchinrotarr(arr,mid+1,end,key);
    }
    if (key>arr[mid] && key<arr[end])
    {
        return searchinrotarr(arr,mid+1,end,key);
    }
    return searchinrotarr(arr,start+1,mid-1,key);
}


signed main()
{
    int arr[]= {6,7,8,9,10,1,2,5};
    int n= 8;
    int k = 1;
    cout<<searchinrotarr(arr,0,n-1,k)<<endl;
}