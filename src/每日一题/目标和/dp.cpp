#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        for(int i : nums) sum+=i;

        int d = sum - target;
        if(d<0 || d % 2 !=0) return 0;
        d = d/2;
        vector<int> dp(d+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j = d;j>=nums[i];j--)
            {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[d];
    }
};