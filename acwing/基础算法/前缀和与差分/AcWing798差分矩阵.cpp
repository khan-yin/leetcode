#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N][N], b[N][N];

// 子矩阵:左上角(x1,y1)到右下角(x2,y2)部分的每个数+c
inline void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1]+=c;
    b[x1][y2+1]-=c;
    b[x2+1][y1]-=c;
    b[x2+1][y2+1]+=c;
}

int main()
{
    int n,m,q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            scanf("%d", &a[i][j]);
    
    for(int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            insert(i,j,i,j,a[i][j]);
    
    while (q -- )
    {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    
    // 构造差分矩阵：即a[i][j]= \sum_{ij}{b[i][j]}
    // 则所求a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j];
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j];
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}