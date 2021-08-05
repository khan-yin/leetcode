// PAT甲级真题1045
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
const int M = 210;

int like[N];
int a[N];
int dp[M][N];//dp[i][j] 表示以a[i]结尾和以b[j]结尾的两个子串的最长公共子序列的长度

int n,m;


int main()
{
    scanf("%d", &n);
    
    cin >> m;
    for (int i = 1; i <= m; i ++ ) cin >> like[i];
    int l;
    cin >> l;
    for (int i = 1; i <= l; i ++ ) cin >> a[i];
    
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= l; j ++ )
        {
            // like[i] != a[j]
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (like[i] == a[j]) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1); //dp[i][j - 1] + 1因为可以对应多个a[j]
        }
    cout<<dp[m][l];
    return 0;
}