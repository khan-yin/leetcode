#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n,m;

int g[N][N]; //稠密图使用prim和邻接矩阵
int dist[N]; 
bool isvisited[N];

int prime(int x)
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    dist[x]=0;
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!isvisited[j] && (t==-1 || dist[t] > dist[j]))
                t= j;
        
        if(dist[t] == INF) return -1;
        //标记访问
        res += dist[t];
        isvisited[t]=true;
        
        //更新dist
        for(int j=1;j<=n;j++)
        {
            dist[j] = min(dist[j],g[t][j]); 
        }
    }
    return res;
}


int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m -- )
    {
        int a,b,c;
        scanf("%d%d%d", &a, &b,&c);
        g[a][b] = g[b][a] = min(g[a][b],c); //无向图
    }
    
    
    int t = prime(1);
    
    if(t==-1)
        cout<<"impossible"<<endl;
    else
        cout<<t<<endl;
    
    return 0;
}