#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int n,m;
int g[N][N]; // 稠密图使用邻接矩阵
int dist[N]; // 存储距离
bool isvisited[N]; // 标志到该节点的距离是否已经被规整为最短距离

int dijstra(int x)
{
    memset(dist, 0x3f, sizeof dist);//初始化所有的dist为无穷大
    dist[x]=0;

    for(int i=0;i<n;i++)//外层循环n次遍历每个节点
    {
        //寻找到未被调整为最短节点当中距离最近的节点编号
        int t = -1;
        for(int j=1;j<=n;j++)
        {
            if(!isvisited[j] && (t==-1 || dist[t]>dist[j]))
                t=j;
        }
        isvisited[t]=true;
        //利用最近的节点t更新dist数组
        for(int j=1;j<=n;j++)
        {
            dist[j] = min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g,0x3f,sizeof g);//初始化邻接矩阵
    while (m -- )
    {
        int x,y,z;
        scanf("%d%d%d", &x, &y,&z);
        g[x][y]= min(g[x][y],z); //对于重边仅记录最小值
    }
    cout<<dijstra(1);//求1 号点到 n 号点的最短距离。
    return 0;
}