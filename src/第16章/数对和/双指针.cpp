#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l<r)
        {
            if(nums[l]+nums[r]==target)
            {
                res.push_back({nums[l],nums[r]});
                l++;
                r--;
            }
            else if(nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        return res;
    }
};