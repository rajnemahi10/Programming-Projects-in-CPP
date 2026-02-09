//brute force
#include<iostream>
using namespace std;
#include<vector>
int main()
{
    int st,end,max,stf,enf,k;
    vector <int> vec;
    vec={3,-4,5,4,-1,7,-8};
    max=vec[0];
    stf=0;
    enf=0;
    int n=vec.size();
    int sum=0;
    // for(st=0;st<n;st++)
    // {   

    //     for(end=st;end<n;end++)
    //     {
    //         sum=0;
    //         for(k=st;k<=end;k++)
    //         {
    //             sum+=vec[k];
    //         }
    //         if(sum>max)
    //         {
    //             stf=st;
    //             enf=end;
    //             max=sum;
    //         }
    //     }

        
    // }
    // for(st=0;st<n;st++)
    // {
    //     sum=0;
    

    //     for(end=st;end<n;end++)
    //     {
    //         sum+=vec[end];
    //         if(sum>max)
    //         {
    //             stf=st;
    //             enf=end;
    //             max=sum;
    //         }
    //     }
    // }
    //Kadane's Algorithm
    for(int i=0;i<n;i++)
    {
        sum+=vec[i];
        if(sum>max)
        {
            max=sum;
        }
        //if ans is negative then sum will always be 0 so this step is at the end
        if(sum<0)
        {
            sum=0;
        }
        
    }
    cout<<max;
    return 0;
}