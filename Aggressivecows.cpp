#include<iostream>
using namespace std;
#include<vector>
int cows(vector<int>arr,int C)
{
    int st=1;
    int end;
    int large=arr[0],small=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
        }
        else if(arr[i]<small)
        {
            small=arr[i];
        }
    }
    end=large-small;
    int mid;
    int ans=0;
    while(st<=end)
    {
        mid=st+(end-st)/2;
        if(isvalid(arr,mid,C))
        {
            ans=mid;
            end=mid-1;

        }
        else
        {
            st=mid+1;
        }
    }
}
bool isvalid(vector<int>arr,int mid,int C)
{
    sort(arr.begin(),arr.end());
    int cows=1;
    int laststallpos=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]-laststallpos>=mid)
        {
            cows++;
            laststallpos=arr[i];
        }
    }
    if(cows==C)
        return true;

    return false;
}