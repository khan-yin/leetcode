// PAT甲级真题1142
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 210;
const int M = 510;


int n,m;
bool g[N][N];
int nodes[N];
bool vis[N];


bool check(int cnt)
{
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            if(i==j) continue;
            if(!g[nodes[i]][nodes[j]]) return false;
        }
    }
    return true;
}

bool check_max(int cnt)
{

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            bool flag = true;
            for(int j = 0;j<cnt;j++)
            {
                if(!g[i][nodes[j]]) flag = false;
            }
            if(flag) return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    while (m -- )
    {
        int a,b;
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = true;
    }

    int k;
    scanf("%d", &k);

    while (k -- )
    {
        memset(vis, 0, sizeof vis);

        int cnt;
        scanf("%d", &cnt);
        for(int i=0;i<cnt;i++) 
        {
            scanf("%d", &nodes[i]);
            vis[nodes[i]]=true;
        }

        if(check(cnt))
        {
            if(!check_max(cnt)) puts("Yes");
            else puts("Not Maximal");
        }
        else puts("Not a Clique");
    }
    return 0;
}
