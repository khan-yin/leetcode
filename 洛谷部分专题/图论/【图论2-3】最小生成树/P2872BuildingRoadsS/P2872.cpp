#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define inf 0x7f
struct Node
{
    int x;
    int y;
};

Node node[1005];
int n,m;
double dist[1005];
bool isvisited[1005];
double distmap[1005][1005];

inline double getdistance(int x1,int x2,int y1,int y2)
{
    return (double)sqrt(pow(double(x1-x2),2)+pow(double(y1-y2),2));//这个地方必须强制double，也可以有其他写法，要不有四个点会输出-nan
}

double ans=0.0;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&node[i].x,&node[i].y);
    }

    //计算出每个点之间的距离，由于是无向图，所以可以减少循环次数。
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            distmap[i][j]=distmap[j][i]=getdistance(node[i].x,node[j].x,node[i].y,node[j].y);
    
    for(int i=1;i<=m;i++)
    {
        int from,to;
        scanf("%d %d",&from,&to);
        distmap[from][to]=0;
        distmap[to][from]=0;
    }
    memset(dist,inf,sizeof(dist));
    int start=1;
    for(int i=1;i<=n;i++)
    {
        if(start==i)
            dist[i]=0;
        else
            dist[i]=distmap[start][i];
        // cout<<i<<" "<<dist[i]<<endl;
    }
    isvisited[start]=true;
    for(int i=1;i<=n-1;i++)
    {
        int minn=inf;
        for(int j=1;j<=n;j++)
        {   //选择最小边
            if(!isvisited[j]&&dist[j]<minn)
            {
                start=j;
                minn=dist[j];
            }
        }

        isvisited[start]=true;
        // cout<<"s:"<<start<<endl;
        for(int j=1;j<=n;j++)
        {   //start加入后其相关边加入更新dist
            if(!isvisited[j]&&distmap[start][j]<dist[j])
            {
                dist[j]=distmap[start][j];
                // cout<<"j"<<j<<" "<<dist[j]<<endl;
            }
        }
    }  
    
    for(int i=1;i<=n;i++)
    {
        ans=ans+dist[i];
    }

    printf("%.2f\n",ans);
    return 0;
}