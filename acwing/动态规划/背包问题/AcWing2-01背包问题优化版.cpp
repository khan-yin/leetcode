#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int v[N],w[N];

int dp[N];

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
        for(int j=V;j>=v[i];j--)
        {
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }

    cout<<dp[V];
    return 0;
}

