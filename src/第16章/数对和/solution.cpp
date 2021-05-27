#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        vector<bool> st(n,false);
        for(int i=0;i<n;i++)
        {
            if(st[i]) continue; 
            st[i]=true;
            int s = lower_bound(nums.begin(),nums.end(),target-nums[i]) - nums.begin();
            int d = upper_bound(nums.begin(),nums.end(),target-nums[i]) - nums.begin();
            for(int j = s;j<d;j++)
            {
                if(st[j]) continue; 
                if(nums[i]+nums[j]==target)
                {
                    st[j]=true;
                    res.push_back({nums[i],nums[j]});
                    break;
                }
            }
        }
        return res;
    }
};