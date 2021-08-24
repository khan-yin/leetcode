#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution {
public:
    int dp[110][100]; // 表示通过i条边到达j的花费
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        memset(dp,0x3f,sizeof dp);
        dp[0][src] = 0;
        for(int len=1;len<=k+1;len++)
        {
            for(auto& item : flights)
            {
                int from = item[0];
                int to = item[1];
                int dis = item[2];
                dp[len][to] = min(dp[len][to],dp[len-1][from] + dis);
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i=0;i<=k+1;i++)
        {
            ans = min(ans,dp[i][dst]);
        }
        return ans==0x3f3f3f3f ? -1 : ans;
    }
};