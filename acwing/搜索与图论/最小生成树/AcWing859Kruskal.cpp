#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, INF =0x3f3f3f3f;
const int M = 2*N;

int n,m;

struct Edge
{
    int x;
    int y;
    int w;
    bool operator < (const Edge & E) const
    {
        return w < E.w;
    }
}edge[M];

int p[N]; //并查集

int find(int x)//找祖宗节点
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    int res = 0;
    int cnt=0;
    sort(edge,edge+m);
    for(int i=1;i<=n;i++) p[i]=i;//初始化并查集
    
    for(int i=0;i<m;i++)
    {
        int x = edge[i].x, y = edge[i].y, w = edge[i].w;
        
        int a = find(x);
        int b = find(y);
        //不是连通的
        if(a!=b)
        {
            p[b] = a;
            res += w;
            cnt++;
        }
    }
    //路径数量<n-1说明不连通
    if (cnt<n-1) return INF;
    return res;
}


int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++ )
    {
        scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].w);
    }
    
    int t = kruskal();
    
    if(t == INF) cout<< "impossible"<<endl;
    else cout<<t<<endl;
    
    return 0;
}
