#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i,j,k,l;
        for(i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(j=i+1;j<nums.size();j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                k=j+1;
                l=nums.size()-1;
                while(k<l)
                {
                    if(nums[k]+nums[l]==target-nums[i]-nums[j])
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(nums[k]+nums[l]>target-nums[i])
                    {
                        l--;
                    }
                    else if(nums[k]+nums[l]<target-nums[i])
                    {
                        k++;
                    }


                    while(k<l && nums[k]==nums[k-1])
                    {
                        k++;
                    }
                    while (k < l && nums[l] == nums[l + 1]) 
                        l--;

                }
            }
        }
        return ans;
    }
};