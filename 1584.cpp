#include<iostream>
using namespace std;
#include<vector>
#include<set>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans=0;
        priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq; // dist & coordinates

        set<pair<int,int>> s;
        pq.push(make_pair(0,make_pair(points[0][0],points[0][1])));

        while(pq.size()>0)
        {
            pair<int,int> curr=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            if(s.count(curr)==0)
            {
                ans+=distance;
                s.insert(curr);
                //accessing neighbors
                for(vector<int> cord:points)
                {
                    
                    if(cord[0] != curr.first || cord[1] != curr.second)

                    {
                        
                        int dist=abs(curr.first-cord[0])+abs(curr.second-cord[1]);
                        pq.push(make_pair(dist,make_pair(cord[0],cord[1])));


                    }
                }
            }
        }
        return ans;
    }
};