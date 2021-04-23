#include<vector>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6,1.0/6);
        for(int i=2;i<=n;i++)
        {
            vector<double> tmp(5*i+1,0);
            for(int j=0;j<dp.size();j++)
            {
                for(int k=0;k<6;k++)
                {
                    tmp[j+k]+=dp[j]*1.0/6;
                }
            }
            dp=tmp;
        }
        return dp;
    }
};