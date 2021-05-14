#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int a[N],s[N];
int dp[N][N];//dp[i][j]表示区间i-j的最小合并代价

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
    
    for(int len=2;len<=n;len++)//枚举长度
        for(int i=1;i + len -1 <=n;i++)//枚举左端点,且右端点保证不越界
        {
            int j = i + len -1;//右端点
            dp[i][j]=1e9;
            for(int k = i;k<j;k++)//区间[i,j]的k重划分
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j] - s[i-1]);
        }
    cout<<dp[1][n]<<endl;//求区间[1,n]的最小代价
    return 0;
}