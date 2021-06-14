#include<vector>
using namespace std;

int dp[5010][5010];
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        dp[0][0] = 1;
        for(int i=1;i<=n;i++)
        {
            int val = coins[i-1];
            for(int j = 0; j<=amount;j++)
            {
                if(j < val){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i][j - val] + dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};