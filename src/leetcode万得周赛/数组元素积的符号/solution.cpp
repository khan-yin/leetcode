#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
    long long ans=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
            return 0;
        else if(nums[i]<0)
            ans*=-1;
            
    }
    return (int) ans;
    }
};