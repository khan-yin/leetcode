#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int dp[1010][1010]; // dp[i][j] 表示当前区间的最长子序列
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int res = 1;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};