#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 1505
int a[MAXN][MAXN];/*数据比较小，我比较懒，所以用邻接矩阵*/
int f[MAXN];//f[i]表示以i为终点的最长路 
int n,m,x,y,z,ans;
int dfs(int x)/*无聊的我要倒着搜*/
{
    int s = 0;/*s表示该点的入度*/
    if(x == 1)
    {
        f[x] = 0;
        return 0;
    }
    if(f[x] > -INF) return f[x];
    for(int i = 1; i <= n; i ++)/*枚举每一条边*/
    {
        s ++;
        if(a[x][i] > -INF)
            f[x] = max(f[x],dfs(i) + a[x][i]);
    }
    if(s == 0) return -INF;//不是1且没有入度，则不可能走这条，返回负无穷 
    return f[x];
}
int main()
{
    memset(a,0xc0,sizeof(a));//初始化为负无穷 
    memset(f,0xc0,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; i ++)
    {
        scanf("%d%d%d",&x,&y,&z);
        a[y][x] = max(a[y][x],z);
    }
    ans = dfs(n);
    if(ans > -INF)
        printf("%d",ans);
    else
        printf("-1");
    return 0;
}