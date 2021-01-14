#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return INT_MIN;
        int sum=nums[0];
        int maxsum=sum;
        for(int i=1;i<nums.size();i++)
        {
            if(sum<0)
                sum=0;
            sum+=nums[i];
            if(sum>maxsum)
                maxsum=sum;
        }
        return maxsum;
    }
};