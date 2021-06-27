#include<vector>
using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int pre = -1;
            bool flag=true;
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                if(pre<nums[j]) pre = nums[j];
                else flag=false;
            }
            if(flag) return flag;
        }
        return false;
    }
};