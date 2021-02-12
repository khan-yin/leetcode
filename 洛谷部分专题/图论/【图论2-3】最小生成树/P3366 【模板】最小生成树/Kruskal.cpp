#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int from;
    int to;
    int weight;
};

Edge edge[200002];

bool cmp(Edge a,Edge b)
{
    return a.weight<b.weight;
}

int f[5002];//并查集

int find(int x)//找所属根节点
{
	return f[x]==x?x:f[x]=find(f[x]);
}

// int find(int x)//并查集部分
// {
//     if (f[x]==x) return x; else 
//     {
//         f[x]=find(f[x]);
//         return f[x];
//     }	
// }

long long ans=0;
int cnt=0;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].weight);
    }

    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(find(edge[i].from)==find(edge[i].to))//属于同一连通块,则已访问
            continue;
        f[find(edge[i].to)]=find(edge[i].from);//将祖先合并
        ans +=edge[i].weight;
        cnt++;
    }

    if(cnt==n-1)
        printf("%lld\n",ans);
    else
        printf("orz\n");
    return 0;
}