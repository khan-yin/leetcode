#include<vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i : stones) sum += i;
        int t = sum / 2;
        vector<int> dp(t+1,0);

        for(int item : stones)
        {
            for(int j = t;j>=item;j--)
            {
                dp[j] = max(dp[j],dp[j-item]+item);
            }
        }
        return sum - 2 * dp[t];
    }
};