// PAT甲级真题1150
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 210;
int n,m;
bool vis[N];
int g[N][N];
int nodes[N];

bool check(int cnt,int &total)
{
    for(int i=0;i+1<cnt;i++)
    {
        if(!g[nodes[i]][nodes[i+1]]) return false;
        total += g[nodes[i]][nodes[i+1]];
        vis[nodes[i]]=true;
    }
    if(nodes[0]!=nodes[cnt-1]) return false;
    for(int i=1;i<=n;i++) if(!vis[i]) return false;
    return true;
}


int main()
{
    scanf("%d%d", &n, &m);
    while (m -- )
    {
        int x,y,d;
        scanf("%d%d%d", &x, &y,&d);
        g[x][y] =g[y][x] = d;
    }
    int k;
    scanf("%d", &k);
    int minid,mintotal=1e9;
    for(int i=1;i<=k;i++)
    {
        memset(vis, 0, sizeof vis);
        int cnt;
        scanf("%d", &cnt);
        for(int j=0;j<cnt;j++) scanf("%d", &nodes[j]);
        int total = 0;
        bool flag = true;
        if(check(cnt,total))
        {
            if(n+1==cnt) printf("Path %d: %d (TS simple cycle)\n",i,total);
            else printf("Path %d: %d (TS cycle)\n",i,total);
            if(total<mintotal)
            {
                mintotal = total;
                minid = i;
            }
        }
        else 
        {
            bool flag = true;
            for(int j=0;j+1<cnt;j++)
            {
                if(!g[nodes[j]][nodes[j+1]])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                printf("Path %d: %d (Not a TS cycle)\n",i,total);
            }
            else
                printf("Path %d: NA (Not a TS cycle)\n",i);
        }
    }

    printf("Shortest Dist(%d) = %d",minid,mintotal);
    return 0;
}