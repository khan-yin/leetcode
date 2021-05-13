// 原理版
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;

int v[N], w[N];

int dp[N][N];


int main()
{
    int n,V;
    
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; i ++ )
        scanf("%d%d", &v[i], &w[i]);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=V;j++)
            for(int k=0;v[i]*k<=j;k++)
                dp[i][j] = max(dp[i][j],dp[i-1][j - v[i]*k]+w[i]*k);
    
    cout<<dp[n][V];    
    return 0;
}

// 朴素版
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int v[N], w[N];

int dp[N][N];


int main()
{
    int n,V;
    
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; i ++ )
        scanf("%d%d", &v[i], &w[i]);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=V;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=v[i])
                dp[i][j] = max(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    
    cout<<dp[n][V];    
    return 0;
}

// 一维优化版
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int v[N], w[N];

int DP[N];

int main()
{
    int n,V;
    
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; i ++ )
        scanf("%d%d", &v[i], &w[i]);
    
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=V;j++)
            DP[j] = max(DP[j],DP[j-v[i]]+w[i]);
    
    cout<<DP[V];    
    return 0;
}