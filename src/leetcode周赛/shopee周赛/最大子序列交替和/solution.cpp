#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//dp[i][0]表示前i个字符的偶数数量的最大交替和
//dp[i][1]表示前i个字符的奇数数量的最大交替和
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        typedef long long LL;
        int n = nums.size();
        const int INF = 1e9;
        vector<vector<LL>> dp(n+1, vector<LL>(2,-INF));
        dp[0][0]=0;
        for(int i =1;i<=n;i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-nums[i-1]);
            dp[i][1] = max(dp[i-1][1],max(0LL,dp[i-1][0])+nums[i-1]);
        }

        return max(dp[n][0],dp[n][1]);
    }
};