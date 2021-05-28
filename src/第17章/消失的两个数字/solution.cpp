#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int t=1;
        int j=0;
        while(res.size()<2)
        {
            while(j<nums.size()&&nums[j]==t)
            {
                t++;
                j++;
            }
            // cout<<t<<endl;
            res.push_back(t);
            t++;
        }
        return res;
    }
};