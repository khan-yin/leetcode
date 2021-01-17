#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> >& res, vector<int>& nums, int start, int len)
    {
        if(start==len)
        {
            res.push_back(nums);
        }
        for(int i=start;i<len;i++)
        {
            swap(nums[start],nums[i]);
            dfs(res,nums,start+1,len);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int len=nums.size();
        dfs(res, nums, 0,len);
        return res;
    }
};