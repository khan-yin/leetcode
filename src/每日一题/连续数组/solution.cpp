#include<vector>
#include<algprithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int sum=0;
        m[0]=-1;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i]==1?1:-1;
            if(m.count(sum))
                res = max(res,i-m[sum]);
            else
                m[sum]=i;
        }
        return res;
    }
};