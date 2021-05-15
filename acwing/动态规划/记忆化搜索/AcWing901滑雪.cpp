#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;
int n,m;
int h[N][N];

int dp[N][N];//dp[i][j]表示从当前i，j位置可以划过的最大长度
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

//记忆化搜索求dp[x][y]
int dfs(int x,int y)
{
    if(dp[x][y]!=-1)
        return dp[x][y];
    
    dp[x][y]=1;
    
    for(int i=0;i<4;i++)
    {
        int nextx = x+dx[i],nexty = y +dy[i];
        if(h[nextx][nexty] < h[x][y] && nextx>0 && nextx<=n && nexty >0 &&nexty<=m)
            dp[x][y] = max(dp[x][y],dfs(nextx,nexty)+1);
    }
    
    return dp[x][y];
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(dp, -1, sizeof dp);//初始化dp用-1标记未被访问的点
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d", &h[i][j]);
    
    int res = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            res = max(res,dfs(i,j));
    
    cout<<res<<endl;
    
    return 0;
}