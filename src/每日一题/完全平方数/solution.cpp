#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        //枚举到根号n
        vector<int> dp(n+1,0x3f);
        dp[0]=0;
        for(int i=1;i*i<=n;i++)
        {
            for(int j = i*i;j<=n;j++)
                dp[j] = min(dp[j],dp[j-i*i]+1);
        }
        return dp[n];
    }
};