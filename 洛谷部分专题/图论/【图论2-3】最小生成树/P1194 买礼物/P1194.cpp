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

Edge edge[10000006];
int f[10005];

int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}


bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}


int a,n;
long long ans=0;
int cnt=0;


int main()
{
    scanf("%d %d",&a,&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int w;
            scanf("%d",&w);
            if(i<=j&&w!=0)//无向图使用并查集存边只取一半
            {
                cnt++;
                edge[cnt].from=i;
                edge[cnt].to=j;
                edge[cnt].w=w;
            }

        }
    }

    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }


    sort(edge+1,edge+cnt+1,cmp);

    int tot=0;
    for(int i=1;i<=cnt;i++)
    {
        int t1 = find(edge[i].from);
        int t2 = find(edge[i].to);
        if(t1==t2) 
        {
            continue;
        }
        else if(t1!=t2)
        {
            f[t2]=t1;
            if(a>edge[i].w) 
                ans+=edge[i].w;
            else
            {
                ans+=a;
            }
            tot++;
        }
        if(tot==n-1)
            break;
    }

    printf("%lld\n",ans+a);
    return 0;
}