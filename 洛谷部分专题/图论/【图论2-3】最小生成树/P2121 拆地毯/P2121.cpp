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
    return a.w>b.w;
}


Edge edge[100005];
int f[100005];

int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}

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

    int tot=0;
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        int t1 = find(edge[i].from);
        int t2 = find(edge[i].to);
        if(t1==t2)
            continue;
        else
        {
            f[t2]=t1;
            ans+=edge[i].w;
            tot++;
        }
        if(tot==k)
            break;
    }
    printf("%lld\n",ans);
    return 0;
}