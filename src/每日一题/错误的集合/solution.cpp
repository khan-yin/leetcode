#include<vector>
using namespace std;

class Solution {
public:
    int cnt[10010];
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int n = nums.size();
        for(int i : nums)
        {
            cnt[i]++;
            if(cnt[i]>1) res[0]=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]==0) 
            {
                res[1]=i;
                break;
            }
        }
        return res;
    }
};