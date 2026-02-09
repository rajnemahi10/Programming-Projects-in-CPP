        #include<iostream>
        using namespace std;
        #include<vector>
        int main(){
            int i,j;
            vector<int>nums={1,2,3,4};
            vector<int>finalans(nums.size(),1);
            int pdt1=nums[0];
            int pdt2=nums[nums.size()-1];
            for(i=1;i<=nums.size()-1;i++)
            {
                finalans[i]=pdt1;
                pdt1*=nums[i];
            }
            for(j=nums.size()-2;j>=0;j--)
            {
                finalans[j]*=pdt2;
                pdt2*=nums[j];
            }
            for(i=0;i<nums.size();i++)
            {
                cout<<finalans[i]<<endl;
            }
    }