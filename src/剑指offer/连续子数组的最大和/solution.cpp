#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxsum=sum;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
                maxsum=nums[i];
            sum+=nums[i];
            //compare 
            if(sum>maxsum)
                maxsum=sum;
            if(sum<0)
                sum=0;
        }
        return maxsum;
    }
};