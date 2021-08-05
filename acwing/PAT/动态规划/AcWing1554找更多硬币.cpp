// PAT甲级真题1068
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
const int M = 110;

int coin[N];

bool dp[N][M]; //dp[i][j] 从前i个物品选出容量为j的最小数

int main()
{
    int n,m; // 硬币数量以及需要支付的金额。
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) scanf("%d", &coin[i]);
    sort(coin+1,coin+n+1,greater<int>());
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=coin[i]) dp[i][j] |= dp[i-1][j-coin[i]];
        }
    }

    if(!dp[n][m]) puts("No Solution");
    else
    {
        bool flag=true;
        while(n)
        {
            if(m>=coin[n] && dp[n-1][m-coin[n]])
            {
                if(flag) flag=false;
                else cout<<' ';
                cout<<coin[n];
                m -= coin[n];
            }
            n--;
        }
    }

    return 0;
}
