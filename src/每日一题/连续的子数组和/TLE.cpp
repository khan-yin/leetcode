#include<vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n+1,0);
        for(int i=1;i<=n;i++) presum[i] = presum[i-1] + nums[i-1];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int s = presum[j]-presum[i-1];
                if(s%k==0) return true;
            }
        }
        return false;
    }
};