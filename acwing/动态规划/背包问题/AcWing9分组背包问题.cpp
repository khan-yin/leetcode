#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int v[N][N],w[N][N],s[N];

int dp[N];

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &s[i]);
        for(int k=1;k<=s[i];k++)
        {
            scanf("%d%d", &v[i][k], &w[i][k]);
        }
    }


    for(int i=1;i<=n;i++)
        for(int j=m;j>=0;j--)
            for(int k=1;k<=s[i];k++)
                if(j>=v[i][k])
                    dp[j] = max(dp[j],dp[j-v[i][k]]+w[i][k]);

    cout<<dp[m]<<endl;
    return 0;
}
