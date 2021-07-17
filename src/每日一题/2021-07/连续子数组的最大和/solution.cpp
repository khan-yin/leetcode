#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int dp[100010]; //以i结尾的最大子序列和
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            dp[i]=nums[i];
        }

        for(int i=1;i<n;i++)
        {
            dp[i] = (dp[i-1] + nums[i]) > dp[i] ? dp[i-1] + nums[i] : dp[i];
        }
        int ans = -1000000;
        for(int i=0;i<n;i++)
            ans = max(ans,dp[i]);
        return ans;
    }
};