#include<iostream>
using namespace std;
#include<vector>
int main()
{
    vector<int> nums;
    nums={1};
    int flag=0;
    int left=0,right=nums.size()-1;
    while(left<=right)
    {
        if(nums[left+1]<nums[left])
        {
            flag=1;
            left++;
        }
        if(nums[right-1]>nums[right])
        {
            flag=1;
            right--;
        }
        if(flag==0)
        {
            break;
        }
        flag=0;

    }
    if(right<=left)
        cout<<0;
    else
        cout<<right<<endl<<left;
    return 0;
}