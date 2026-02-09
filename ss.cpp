#include<iostream>
using namespace std;
#include <stack>
#include <vector>
#include <string>
#include <queue>
void pushAtBottom(stack<int>&s,int value)
{
    if(s.empty())
    {
        s.push(value);
        return;
    }
    int val=s.top();
    s.pop();
    pushAtBottom(s,value);
    s.push(val);
}

void recurse(stack <int>&s){
    if(s.empty())
    {
        return;
    }

    int val=s.top();
    s.pop();
    recurse(s);
    pushAtBottom(s,val);
}

void stock_span(vector<int> p)
{
    stack<int> s;
    vector<int> prevHigh;
    

    for(int i=0;i<p.size();i++)
    {
        while(!s.empty())
        {
            if(p[i]>=p[s.top()])
            {
                s.pop();
            }
            else{
                break;
            }
        }
        if(s.empty())
        {
            prevHigh.push_back(-1);
        }
        else{
            prevHigh.push_back(s.top());
        }
        s.push(i);
    }
    for(int j=0;j<p.size();j++)
    {
        cout<<j-prevHigh[j]<<endl;
        
    }


}

// int main()
// {
//     vector<int> p={100,80,60,70,60,85,100};
//     stock_span(p);
// }

void nextGreaterElement(vector<int>&arr){
    vector<int>ans(arr.size());
    stack<int>s;
    for(int i=arr.size()-1;i>=0;i--)
    {
        while(!s.empty() && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }


}

bool duplicateParanthesis(string s){
    stack<char>t;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=')' && s[i]!='}' && s[i]!=']')
        {
            t.push(s[i]);
        }
        else
        {
            int r=0;
            char ch;
            if(s[i]==')')
                ch='(';
            
            if(s[i]==']')
                ch='[';
            
            if(s[i]=='}')
                ch='{';
            while(t.top()!=ch)
            {
                r++;
                t.pop();
            }
            if(r==0)
                return true;
            t.pop();
        }
    }
    return false;


}
// int main(){
//     string s="((a+b))";
//     cout<<duplicateParanthesis(s)<<endl;
//     return 0;
// }

vector<char> NonRepeatingLetter(string str){
    int freq[26]={0};
    queue <char> q;
    vector<char>ans;
    for(char ch : str){
        freq[ch-'a']+=1;
        q.push(ch);

        while(!q.empty())
        {
            if(freq[q.front()]==1)
            {
                ans.push_back(q.front());
                break;
            }
            else{
                q.pop();
            }
        }
        if(q.empty())
            ans.push_back('0');
        
    }
    return ans;
}

bool compare(pair<int,int> p1,pair<int,int> p2){
    return (double)((p1.first*1.0)/p1.second)>(double)((p2.first*1.0)/p2.second);
}

double fractionalKnapsack(vector<int>value,vector<int>weight,int W)
{
    vector<pair<int,int>> pairs (value.size(),make_pair(0,0));
    double ans=0;

    for(int i=0;i<value.size();i++)
    {
        pairs[i].first=value[i];
        pairs[i].second=weight[i];
    }
    sort(pairs.begin(),pairs.end(),compare);
    int j=0;
    while(j<value.size() && W!=0)
    {
        
        if(pairs[j].second<=W)
        {
            W-=pairs[j].second;
            ans+=(double)pairs[j].first;
        }
        else
        {
            ans+=(double)((double)((pairs[j].first*1.0)/pairs[j].second)*W);
            W=0;
        }
        j++;
    }
    return ans;
}

int indianCoins(int V){
    int arr[9]={1,2,5,10,20,50,100,500,2000};
    int i=8;
    int count=0;

    while(i>=0 && V<arr[i])
        i--;

    while(i>=0 && V>=arr[i])
    {
        V-=arr[i];
        count++;
        if(V<arr[i])
        {
            while(V<arr[i] && i>=0)
                i--;
        }
        if(V<=0 || i<0)
            break;
    }
    return count;

}

int indianCoin(int V)
{ 
    int arr[9]={1,2,5,10,20,50,100,500,2000};
    int i=0,count=0;
    for(i=8;i>=0;i--)
    {
        if(V>=arr[i])
        {
            count += V/arr[i];
            V=V%arr[i];
            
        }
        if(V==0)
            break;
        
    }
    return count;
}
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}
int JobSequencing(vector<int>job,vector<int>profit) {
    vector<pair<int,int>> pairs(profit.size(),make_pair(0,0));
    for(int j=0;j<profit.size();j++)
    {
        pairs[j].first=job[j];
        pairs[j].second=profit[j];
    }
    sort(pairs.begin(), pairs.end(), compare);

    int profits = pairs[0].second;
    int time = pairs[0].first;
    int i;

    for (i = 1; i < profit.size(); i++) {
        if (pairs[i].first <time) {
            profits += pairs[i].second;
            time = pairs[i].first;
        }
    }

    return profits;
}

int height(Node* root)
{

    if(root==NULL)
        return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);

    return 1+max(lh,rh);
}

int diameter(Node* root){

    if(root==NULL)
        return 0;
    
    int hmax=height(root->left)+height(root->right);
    int smax=max(diameter(root->left),diameter(root->right));

    return max(hmax,smax);

}
pair<int,int> diam(Node*root)
{
    if(root==NULL)
        return (make_pair(0,0));
    pair<int,int> left=diam(root->left);
    pair<int,int>  right=diam(root->right);
    int currdiam=left.first+right.first+1;
    int leftdiam=left.second;
    int rightdiam=right.second;

    int height=1+max(left.first,right.first);

    int diameter=max(currdiam,max(leftdiam,rightdiam));

    return (make_pair(height,diameter));
}
