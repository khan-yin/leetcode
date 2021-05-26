#include<vector>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> dp(n);//前i个元素的最大结果
        //选择i 则dp[i-2] 不选 dp[i-1]
        for(int i = 0;i<n;i++)
            dp[i] = nums[i];
        for(int i=1;i<nums.size();i++)
        {
            dp[i] = max(dp[i],dp[i-1]);//不选择要i
            if(i-2>=0) dp[i] = max(dp[i],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};