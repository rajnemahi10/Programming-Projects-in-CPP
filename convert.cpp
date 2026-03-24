#include<iostream>
using namespace std;
#include<string>

string best=" ";
//assuming s2 is larger than s1

void LongestConsecutiveSub(string s1,string s2,int i, int j,string ans,int flag,int startIdx)
{
    if(i>=s1.size() || j>=s2.size())
    {
        return;
    }
    if(s1[i]==s2[j] && flag==0)
    {
        startIdx=j;
        ans.push_back(s1[i]);
        flag=1;
        LongestConsecutiveSub(s1,s2,i+1,j+1,ans,flag,startIdx);
        
    }

    else if(s1[i]!=s2[j] && flag==1)
    {
        if(ans.length()>best.length())
        {
            best=ans;
            ans="";
            flag=0;
            LongestConsecutiveSub(s1,s2,0,j+1,ans,flag,startIdx);

        }
    }
    else  if(s1[i]==s2[j])
    {
        ans.push_back(s1[i]);
        LongestConsecutiveSub(s1,s2,i+1,j+1,ans,flag,startIdx);
    }    
}