#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct horse
{
    int x;//横坐标
    int y;//纵坐标
};
int dx[9]={0,2, 2, 1,-1,-2,-2,-1,1};
int dy[9]={0,1,-1,-2,-2,-1, 1, 2,2};
bool visit[402][402];
int road[405][405];
int n;//横坐标范围
int m;//纵坐标范围
int count=0;
int main()
{
    horse horse0,top;
    std::ios::sync_with_stdio;
    cin>>n>>m>>horse0.x>>horse0.y;
    memset(visit,false,sizeof(visit));
    memset(road,-1,sizeof(road));
    queue<horse> point;
    point.push(horse0);
    visit[horse0.x][horse0.y]=true;
    road[horse0.x][horse0.y]=0;
    while(!point.empty())
    {
        top=point.front();
        point.pop();
        for(int i=1;i<=8;i++)
        {
            horse xhorse;
            xhorse.x=top.x+dx[i];
            xhorse.y=top.y+dy[i];
            if(xhorse.x>=1&&xhorse.x<=n&&xhorse.y>=1&&xhorse.y<=m&&visit[xhorse.x][xhorse.y]==false)
            {
                visit[xhorse.x][xhorse.y]=true;
                road[xhorse.x][xhorse.y]=road[top.x][top.y]+1;
                point.push(xhorse);
            }
        }
    }
     for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)
            printf("%-5d", road[i][j]);
        printf("\n");
    }
    return 0;
}