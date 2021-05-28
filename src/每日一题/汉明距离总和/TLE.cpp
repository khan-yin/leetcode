#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int get(int x,int y)
    {
        int t = x^y;
        int cnt=0;
        while(t)
        {
            cnt++;
            t &= t-1;
        }
        return cnt;
    }
    int totalHammingDistance(vector<int>& nums) {
        int res  = 0;
        for(int i = 0 ;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                res += get(nums[i],nums[j]);
            }
        }
        return res;
    }
};