// PAT甲级真题1122
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int N = 210;
int n,m;
bool g[N][N];
bool vis[N];
int nodes[2*N];


bool check(int cnt)
{
    // 节点数目和首尾节点不一致，节点数目为n+1就保证了如果是哈密顿图则一定没有重复路径
    if(nodes[0] != nodes[cnt-1] || cnt != n+1) return false;
    memset(vis, 0, sizeof vis);

    // 节点路径是否存在
    for(int i=0;i<cnt-1;i++)
    {
        if(!g[nodes[i]][nodes[i+1]]) return false;
        vis[nodes[i]]=true;
    }
    // 节点是否全部被访问
    for(int i=1;i<=n;i++) if(!vis[i]) return false;
    return true;
}

int main()
{
    memset(g, 0, sizeof g);
    scanf("%d%d", &n, &m);
    while (m -- )
    {
        int a,b;
        cin >> a>>b;
        g[a][b] = true;
        g[b][a] = true;
    }
    int k;
    scanf("%d",&k);
    while(k -- )
    {
        int cnt;
        cin >> cnt;
        for (int i = 0; i < cnt; i ++ ) cin >> nodes[i];

        if(check(cnt))
        {
            puts("YES");
        }
        else
            puts("NO");
    }
    
    return 0;
}