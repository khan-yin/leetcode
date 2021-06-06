#include<vector>
#include<string>
#include<cstring>
using namespace std;


int dp[700][700];//i个0，j个1时的最大子集个数
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,0,sizeof dp);
        for(string s : strs)
        {
            int zero=0,one=0;
            for(char c: s) 
            {
                if(c=='0') zero++;
                else one++;
            }
            for(int i=m;i>=zero;i--)
            {
                for(int j=n;j>=one;j--)
                {
                    dp[i][j] = max(dp[i][j],dp[i-zero][j-one]+1);
                }
            }
        }
        return dp[m][n];
    }
};