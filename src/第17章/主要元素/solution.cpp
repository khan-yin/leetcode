#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(auto i : nums)
        {
            m[i]++;
            if(m[i]>n/2) return i;
        }
        return -1;
    }
};