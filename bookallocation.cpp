#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int Book_Allocation(vector<int>& books,int m) {
        if(m>books.size())
        {
            return -1;
        }
        int st=0, end=0;
        int mid=0;
        int ans=0;
        for(int i:books)
        {
            end+=i;
        }
        while(st<=end)
        {
            mid=st+(end-st)/2;
            if(check_validity(books,mid,m))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return ans;

    }

    bool check_validity(vector<int>& books,int mid,int m)
    {
        int st=1;
        int book=0;
        for(int i=0;i<books.size();i++)
        {
            if(books[i]>mid)
            {
                return false;
            }
            if(book+books[i]<=mid)
            {
                book+=books[i];
            }
            else
            {
                st++;
                book=books[i];
            }
        }
        if(st>m)
        {
            return false;
        }
        return true;
        //return students > m ? false : true 

    }
};