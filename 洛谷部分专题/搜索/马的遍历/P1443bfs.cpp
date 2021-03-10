#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int n,m;
int x_0,y_0;
struct horse
{
    int x;//横坐标
    int y;//纵坐标
};
int map[405][405];
int dx[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dy[8] = {-1,  1, -2,  2, -2, 2, -1, 1};
bool isvisted[405][405];

int main()
{
    scanf("%d %d %d %d",&n,&m,&x_0,&y_0);
    memset(map,-1,sizeof(map));
    isvisted[x_0][y_0]=true;
    map[x_0][y_0]=0;
    horse h;
    h.x=x_0;
    h.y=y_0;
    queue<horse> q;
    q.push(h);
    while(!q.empty())
    {
        horse top=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            horse temp;
            temp.x=top.x+dx[i];
            temp.y=top.y+dy[i];
            if(temp.x>=1&&temp.x<=n&&temp.y>=1&&temp.y<=m&&!isvisted[temp.x][temp.y])
            {
                isvisted[temp.x][temp.y]=true;
                map[temp.x][temp.y]=map[top.x][top.y]+1;//关键代码
                q.push(temp);
            }
        }
    }

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