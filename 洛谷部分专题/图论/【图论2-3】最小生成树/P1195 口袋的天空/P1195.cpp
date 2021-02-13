#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

struct Edge
{
    int from;
    int to;
    int w;
};

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}


Edge edge[100005];
int f[100005];

int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}


//连接一条边----连通块数量减一 k个连通块-----连（n-k）边 
//运用kruskal算法的思想：每次连可以连的边中代价最小的 （贪心） 使用 并查集维护
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        f[i]=i;
    }

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].w);
    }

    sort(edge+1,edge+m+1,cmp);

    int num=n-k;
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        if(num==0)
            break;
        int t1 = find(edge[i].from);
        int t2 = find(edge[i].to);
        if(t1==t2)
            continue;
        else
        {
            f[t2]=t1;
            ans+=edge[i].w;
            num--;
        }
    }
    if(num)
        cout<<"No Answer"<<endl;
    else
        printf("%lld\n",ans);
    return 0;
}