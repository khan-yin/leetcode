#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=10005,maxm=20005;

int n,m,s,t;

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

Edge edge[maxm];
int f[maxn];

//并查集
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}



int main()
{
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].w);
    }

    sort(edge+1,edge+m+1,cmp);

    for(int i=1;i<=n;i++)
        f[i]=i;
    
    for(int i=1;i<=m;i++)
    {
        int r1 = find(edge[i].from);
        int r2 = find(edge[i].to);
        if (r1==r2) 
            continue;
        else
            f[r2] = r1;
        
        if(find(s)==find(t))
        {
            cout<<edge[i].w<<endl;
            return 0;
        }
    }
    return 0;
}