#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& nums,int pos,int res)
    {
        if(pos==nums.size())
        {
            return res;
        }
        //当前位置需要计算
        int a = dfs(nums,pos+1,res^nums[pos]);
        //当前位置不计算
        int b =dfs(nums,pos+1,res);
        return a+b;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        res = dfs(nums,0,0);
        return res;
    }
};