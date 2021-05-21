#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(sum<0)
            {
                sum=0;
            }
            sum+=nums[i];
            res = max(res,sum);
        }
        return res;
    }
};