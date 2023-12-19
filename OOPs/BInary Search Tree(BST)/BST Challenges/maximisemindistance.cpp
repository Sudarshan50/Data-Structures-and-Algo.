#include<iostream>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define br cout<<endl
#define ll left 
#define rr right

bool isfeasible(int arr[],int mid,int n,int k)
{
    int pos = arr[0];int element = 1;
    rep(i,1,n)
    {
        if (arr[i]-pos >= mid)
        {
            pos = arr[i];
            element++;
            if (element == k)
            {
                return true;
            }   
        }
    }
    return false;
}

int maxmindis(int arr[],int n,int k)
{
    sort(arr,arr+n);
    int result = -1;
    int left = 1;int right = arr[n-1];
    while (left<right)
    {
        int mid = (left+right)/2;
        if(isfeasible(arr,mid,n,k))
        {
            result = max(result,mid);
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

signed main()
{
    int arr[] = {1,2,4,8,9};
    int n =5;
    int k =3;
    cout<<maxmindis(arr,n,k)<<endl;
}