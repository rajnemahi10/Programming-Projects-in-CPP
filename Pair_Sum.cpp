#include<iostream>
using namespace std;
#include<vector>
int main()
{
    vector<int> nums={2,7,11,15};
    int target=13;
    int i,j;
    int pairsum=0;
    int flag=0,index1=0,index2=0;

    // for(i=0;i<nums.size();i++)
    // {
    //     pairsum=nums[i];

    //     for(j=i+1;j<nums.size();j++)
    //     {
    //         pairsum+=nums[j];
    //         if(pairsum==target)
    //         {
    //             flag=1;
    //             index1=i;
    //             index2=j;
    //             break;
    //         }
    //         pairsum=nums[i];
    //     }
    //     if(flag==1)
    //         break;
    // }
    //2 pointer approach
    int left=0;
    int right=nums.size()-1;
    while(left<=right)
    {
        pairsum=nums[left]+nums[right];
        if(target>pairsum)
        {
            left++;
        }
        else if(target<pairsum)
        {
            right--;
        }
        else if(target==pairsum)
        {
            index1=left;
            index2=right;
            break;
        }
    }
    cout<<index1<<endl;
    cout<<index2<<endl;
    return 0;
}
