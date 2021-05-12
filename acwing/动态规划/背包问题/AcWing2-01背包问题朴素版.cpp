#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int v[N],w[N];

int dp[N][N];

int main()
{
    int n,V;
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d%d", &v[i], &w[i]);
    }
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=V;j++)
        {
            dp[i][j] = dp[i - 1][j]; //不选择第i个物品的最大价值
            if(j-v[i]>=0)
                dp[i][j] = max(dp[i-1][j],dp[i - 1][j-v[i]]+w[i]);//取不选择第i个物品，和选择了i后的最大价值
        }
    }
    
    cout<<dp[n][V];
    return 0;
}

