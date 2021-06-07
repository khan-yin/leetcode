#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int cnt=0,target;
    void dfs(int m,vector<int>& nums,int sum)
    {
        if(m==nums.size())
        {
            if(sum==target) cnt++;
            return;
        }
        
        dfs(m+1,nums,sum+nums[m]);
        dfs(m+1,nums,sum-nums[m]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        dfs(0,nums,0);
        return this->cnt;
    }
};