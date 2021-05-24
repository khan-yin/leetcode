#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        //二进制枚举
        for(int i=0;i < 1 << n;i++)
        {
            int s=0;
            for(int j=0;j<n;j++)
            {
                //第j位上的二进制数
                if(i >> j & 1)
                    s^=nums[j];
            }
            res +=s;
        }
        return res;
    }
};