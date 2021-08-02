// PAT甲级真题1030
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 510;
const int inf = 0x3f3f3f3f; 

int g[N][N];
int c[N][N];
int dist[N],cost[N];
bool vis[N];
int pre[N];
int n, m, S, T;


void dijkstra(int x)
{
    memset(dist, inf, sizeof dist);
    memset(cost, inf, sizeof cost);
    dist[x] = 0;
    cost[x] = 0;

    for(int i=0;i<n;i++)
    {
        int t = -1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j] && (t==-1 || dist[t] > dist[j]))
                t = j;
        }
        if(t==-1) break;
        vis[t] = true;

        for(int j=0;j<n;j++)
        {
            if(!vis[j])
            {
                if(dist[j] > dist[t] + g[t][j])
                {
                    dist[j] = dist[t] + g[t][j];
                    cost[j] = cost[t] + c[t][j];
                    pre[j] = t;
                }
                else if(dist[j] == dist[t] + g[t][j] && cost[j] > cost[t]+c[t][j])
                {
                    cost[j] = cost[t] + c[t][j];
                    pre[j] =t;
                }
            }
        }
    }
}



int main()
{
    scanf("%d%d%d%d", &n, &m,&S,&T);
    memset(g, inf, sizeof g);
    memset(c,inf,sizeof c);
    while (m -- )
    {
        int  a,b,x,y;
        scanf("%d%d%d%d", &a, &b,&x,&y);
        if(g[a][b]>x)
        {
            g[a][b] = g[b][a] = x;
            c[a][b] = c[b][a] = y;
        }
        else if(x==g[a][b] && y < c[a][b])
        {
            c[a][b] = c[b][a] = y;
        }

    }

    dijkstra(S);

    vector<int> path;
    for(int i = T;i!=S;i=pre[i]) path.push_back(i);
    path.push_back(S);

    for(int i=path.size()-1;i>=0;i--) cout<<path[i]<<' ';

    cout<<dist[T]<<' '<<cost[T];
    return 0;
}
