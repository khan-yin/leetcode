#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;

char a[N],b[N];
int dp[N][N];//dp[i][j] 表示以a[i]结尾和以b[j]结尾的两个子串的最长公共子序列的长度

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", a+1,b+1);
    
    for(int i=1;i<=n;i++)
        for (int j = 1; j <= m; j ++ )
        {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]) dp[i][j] = max(dp[i-1][j-1]+1,dp[i][j]);
        }
    
    cout<<dp[n][m]<<endl;
    return 0;
}