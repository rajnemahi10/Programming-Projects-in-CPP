#include<iostream>
using namespace std;
#include<vector>
int painter(vector<int>lengths, int N)
{
    int st=lengths[0],end,ans=0;
    for(int j=1;j<lengths.size();j++)
    {
        if(lengths[j]>st)
        {
            st=lengths[j];
        }
    }
    for(int i:lengths)
    {
        end+=i;
    }
    int mid=0;
    while(st<=end)
    {
        mid=st+(end-st)/2;
        if(isvalid(lengths,mid,N))
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
bool isvalid(vector<int>lengths, int mid, int N)
{
    int painters=0,sum=0;
    for(int i=0;i<lengths.size();i++)
    {
        if(lengths[i]>mid)
            return false;
        if(lengths[i]+sum<=mid)
        {
            sum+=lengths[i];
        }
        else
        {   
            painters++;
            sum=lengths[i];
        }

    }
    if(painters>N)
        return false;
    return true;
}