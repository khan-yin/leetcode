#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        long long cnt=0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>target)
                break;
            int index = upper_bound(nums.begin(),nums.end(),target-nums[i])-nums.begin();
            if(index-i-1<0)
                continue;
            cnt+=(index-i-1);
        }
       
        return (int)(cnt % 1000000007);
    }
};