#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9+7;


int dp[N];//dp[i]表示总和为i的所有方案数

int main()
{
    int n;
    scanf("%d", &n);
    
    dp[0] = 1;
    //枚举前i个整数
    for(int i=1; i<=n;i++)
        for(int j=i;j<=n;j++)//枚举是否选择i的总和为j的方案数
            dp[j] = (dp[j]+dp[j-i]) % mod;
    cout<<dp[n]<<endl;
    return 0;
}