#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n+1,0);
        for(int i=1;i<=n;i++) presum[i] = presum[i-1] + nums[i-1];
        unordered_set<int> s;
        for(int i=2;i<=n;i++)
        {
            s.insert(presum[i-2]%k);
            if (s.count(presum[i] % k)) return true;
        }
        return false;
    }
};