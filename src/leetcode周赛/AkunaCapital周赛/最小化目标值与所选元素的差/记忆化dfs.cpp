#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int m,n;
    int ans=0x3f3f3f3f;
    int target;
    bool dp[80][5000];//前i行和恰好为j的情况是否存在
    void dfs(int i,int sum,vector<vector<int>>& mat)
    {
        if(sum - target > ans || dp[i][sum]) return;
        dp[i][sum]=true;

        if(i==m)
        {
            ans = min(ans,abs(sum-target));
            return;
        }

        for(int k=0;k<n;k++)
        {
            dfs(i+1,sum+mat[i][k],mat);
        }
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->m = mat.size();
        this->n = mat[0].size();
        this->target = target;
        dfs(0,0,mat);
        return this->ans;
    }
};