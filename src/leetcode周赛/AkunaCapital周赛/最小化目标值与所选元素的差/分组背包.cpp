#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool dp[80][5000];//前i行和恰好为j的情况是否存在
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<n;i++)
        {
            dp[0][mat[0][i]]=true;
        }

        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int num = mat[i][j];
                for(int t=num;t<5000;t++)
                {
                    if(dp[i-1][t-num])
                    {
                        dp[i][t]=true;
                        // cout<<i<<' '<<j<<' '<<t<<endl;
                        // dp[i][t] = dp[i][t] || dp[i-1][t-mat[i][j]];
                    }
                }
            }
        }
        int ans=0x3f3f3f3f;
        for(int i=1;i<5000;i++)
        {
            if(dp[m-1][i])
                ans = min(ans,abs(i-target));
        }
        return ans;
    }
};