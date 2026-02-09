#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include <queue>

int main(){
    
    vector<int> nums = {7, 2, 5, 2, 9, 9, 3, 3, 5};
    // unordered_map<int,int>freq1;
    // unordered_map<int,int>freq2;
    // queue<int>q1;
    // queue<int>q2;
    
    // for(int i:nums){
    //     freq1[i]++;
    //     freq2[i]++;
    // }

    // int l=nums.size()-1;
    // int r=0;

    // int ans=0;

    
    // while(r<nums.size() || l>=0)//r++ && l--
    // {
    //     if(r<nums.size())
    //     {
    //         q1.push(nums[r]);
    //         freq1[nums[r]]--;
    //         if(freq1[nums[r]]==0)
    //         {
    //             while(!q1.empty()){
    //                 if(freq1[q1.front()]!=0)
    //                     break;
                    
    //                 q1.pop();
    //             }
    //             if(q1.empty()){
    //                 ans+=1;
    //             }
                
    //         }
    //         r++;
    //     }

    //     if(l>=0)
    //     {
    //         q2.push(nums[l]);
    //         freq2[nums[l]]--;
    //         if(freq2[nums[l]]==0)
    //         {
    //             while(!q2.empty()){
    //                 if(freq2[q2.front()]!=0)
    //                     break;
                    
    //                 q2.pop();
    //             }
    //             if(q2.empty()){
    //                 ans+=1;
    //             }
                
    //         }
    //         l--;
    //     }


    // }
    // cout<<ans<<endl;
    // return 0;
    int end=0;
    int ans=0;
    int count=0;
    unordered_map<int,int>ends;
    for(int j=0;j<nums.size();j++)
    {
        ends[nums[j]]=j;
    }
    for(int i=0;i<nums.size();i++)
    {
        end=max(ends[nums[i]],end);
        if(end==i)
        {
            count++;
            ans+=1+count;
        }
    }
    
}