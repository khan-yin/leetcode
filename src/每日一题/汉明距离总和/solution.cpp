#include<vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        for(int i=0;i<31;i++)
        {
            int c = 0;
            for(int item : nums)
            {
                c += (item>>i) & 1;
            }
            ans += c*(n-c);
        }
        return ans;
    }
};