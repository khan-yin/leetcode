#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int t = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
                t = min(t,abs(i-start));
        }
        return t;
    }
};