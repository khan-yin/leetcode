class Solution {
public:
    int dfs(int x)
    {
        if(dp[x]) return dp[x];
        if(x==0) 
        {
            dp[x]=0;
            return dp[x];
        }
        else if(x==1)
        {
            dp[x]=1;
            return dp[x];
        }
        else if(x==2) 
        {
            dp[x]=1;
            return dp[x];
        }
        else 
        {
            dp[x] =  dfs(x-3) + dfs(x-2) + dfs(x-1);
            return dp[x];
        }
    }
    int dp[40] = {0};
    int tribonacci(int n) {
        return dfs(n);
    }
};