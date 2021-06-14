#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

int dp[5050];
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};