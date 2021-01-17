#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;
public:
    void dfs(int cnt,vector<int>& nums)
    {
        if(cnt==nums.size())
        {
            ans.push_back(t);
            return;
        }
        //加入当前元素
        t.push_back(nums[cnt]);
        dfs(cnt+1,nums);
        t.pop_back();
        //跳过当前元素
        dfs(cnt+1,nums);
    }   

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }
};