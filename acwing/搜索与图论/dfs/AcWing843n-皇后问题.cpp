#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;
int n;
char g[N][N];
bool col[N],xandy[N],xsuby[N];

void dfs(int row)
{
    if(row==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%c",g[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i] || xandy[row+i] || xsuby[n - row + i]) continue; 
        col[i] = xandy[row+i] = xsuby[n - row + i] = true;
        g[row][i]='Q';
        dfs(row+1);
        g[row][i]='.';
        col[i] = xandy[row+i] = xsuby[n - row + i] = false;
        
    }
    
}

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j]='.';
    
    dfs(1);
    return 0;
}