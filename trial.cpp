#include <iostream>
using namespace std;
#include <vector>
int main()
{
    vector<int> nums = {-2, 3, -4};
    vector<int> dp(nums.size() + 1);
    dp[0] = 0;
    int currMax = INT_MIN;
    int track = 1;
    for (int i = 1; i < nums.size() + 1; i++)
    {
        if (track * nums[i - 1] > currMax)
        {
            dp[i] = track * nums[i - 1];
            track = dp[i];
            currMax = dp[i];
        }
        else if (track * nums[i - 1] < currMax)
        {
            dp[i] = currMax;
            track = track * nums[i - 1];
        }
    }
    for (int i = 0; i < nums.size() + 1; i++)
    {
        cout << dp[i] << " ";
    }
}