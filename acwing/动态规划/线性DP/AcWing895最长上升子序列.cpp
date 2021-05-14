#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int a[N],dp[N];//表示以i位置为结尾的序列的最长上升子序列长度

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i]) dp[i] = max(dp[j]+1,dp[i]);
        }
    }

    int res = 0;
    for(int i=1;i<=n;i++)
    {
        res = max(res ,dp[i]);
    }

    cout<<res<<endl;
    return 0;
}
