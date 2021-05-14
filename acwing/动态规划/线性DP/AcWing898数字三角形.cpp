#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510,INF=1e9;

int a[N][N];
int dp[N][N];//dp[i][j]表示以第i行第j列位置结尾的路径集合的最大路径和

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i+1;j++)
        {
            // a[i][j] = -INF;
            dp[i][j] = -INF;
        }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d", &a[i][j]);
    
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
            // cout<<"ps"<<dp[3][3] << " "<<dp[2][2]<<" "<<dp[2][3]<<" "<< a[2][2]<<endl;
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=i;j++)
    //         printf("%d ", dp[i][j]);
    //     printf("\n");
    // }
    int res = -INF;
    for(int i=1;i<=n;i++)
        res = max(res,dp[n][i]);
    cout<<res<<endl;
    return 0;
}