#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF =1e9;
int n,m,Q;

int g[N][N];

void floyd()
{
    for(int k=1;k<=n;k++)
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &Q);
    for(int i=1;i<=n;i++)
        for (int j = 1; j <= n; j ++ )
            if(i==j) g[i][j]=0;
            else g[i][j]=INF;
    
    while (m -- )
    {
        int x,y,z;
        scanf("%d%d%d", &x, &y,&z);
        g[x][y] = min(g[x][y],z);
    }
    
    
    floyd();
    
    while(Q --)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        if(g[a][b] > INF /2) printf("impossible\n"); //因为存在负权边，如果是不连通的话可能会比INF小一些，不一定等于INF
        else printf("%d\n",g[a][b]);
    }
    
    return 0;
}