// PAT甲级真题1093
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, mod =1e9 + 7;

char s[N], p[] = " PAT";

int dp[N][4]; // 前i个字符的所到达的第j个状态的数量



int main()
{
    cin >> s + 1; // 相当于输入在s[0]之后,s[0]为空
    int n = strlen(s + 1);
    dp[0][0]=1;
    for (int i = 1; i <= n; i ++ )
    {
        for(int j=0;j<=3;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(s[i]==p[j]) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
        }
    }
    
    cout<<dp[n][3];
    return 0;
}