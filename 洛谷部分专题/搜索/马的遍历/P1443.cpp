#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int map[405][405];
int dx[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dy[8] = {-1,  1, -2,  2, -2, 2, -1, 1};
bool isvisted[405][405];
int x_0,y_0;
int n,m;


void dfs(int x,int y,int step)
{
    //越界
    if(x<=0 || x>n || y<=0 || y>m)
        return;
    //被访问而且step比最佳步数要大就无需在计算，剪枝
    if(isvisted[x][y]&&map[x][y]!=-1&&map[x][y]<=step)
        return;
    else
        map[x][y]= (map[x][y]==-1) ? step : min(map[x][y],step);
    isvisted[x][y]=true;
    for(int i=0;i<8;i++)
    {
        dfs(x+dx[i],y+dy[i],step+1);
    }
}



int main()
{
    int step=0;
    scanf("%d %d %d %d",&n,&m,&x_0,&y_0);
    memset(map,-1,sizeof(map));
    dfs(x_0,y_0,step);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%-5d",map[i][j]);
        }
        printf("\n");
    }

    return 0;
}