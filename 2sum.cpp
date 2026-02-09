#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int> main()
{
            vector<int> nums;
            int target;
            sort(nums.begin(),nums.end());
            int small=0;
            int large=nums.size()-1;
            vector<int> ans(2);
            while(small<large)
            {
                if(nums[small]+nums[large]==target)
                {
                    ans[0]=small;
                    ans[1]=large;
                    return ans;
                }
                if(nums[small]+nums[large]<target)
                {
                    small++;
                }
                else
                {
                    large--;
                }
            }
            return ans;
 }
