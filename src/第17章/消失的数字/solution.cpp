#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int t=0;
        int j=0;
        while(j<nums.size()&&nums[j]==t)
        {
            t++;
            j++;
        }
        return t;
    }
};
