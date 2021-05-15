#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, mod =1e9+7;
int dp[N][N];//dp[i][j]前i个数的总和为j的方案数

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i-1][j] % mod;
            if(j>=i)
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % mod;
        }
    cout<<dp[n][n]<<endl;
    return 0;
}