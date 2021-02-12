#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int x;
    int y;
    int weight;
}edge[200006];
int pre[5005];
bool visited[5005];
int m;//边
int n;//顶点
bool comp(Edge x,Edge y)
{
    return x.weight<y.weight;
}

int find(int x)
{
    return pre[x]==x ? x : pre[x]=find(pre[x]);
}


int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        pre[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].weight);
    }
    sort(edge+1,edge+m+1,comp);
    int c=0;
    int sum=0;
    bool flag=true;   
    int m1=find(edge[1].x);
    for(int i=1;i<=m;i++)
    {
        int t1=find(edge[i].x);
        int t2=find(edge[i].y);
        if(t1!=t2)
        {
           pre[t2]=t1;
         //  c++;
            sum+=edge[i].weight;
        }
       // if(c==n-1)
      //  break;
    }
     m1=find(1);
    for(int i=1;i<=n;i++)
    {
        if(pre[i]!=m1)
        {
             printf("orz");
             return 0;
        }
         
    }
    if(flag)
    {
        printf("%d",sum);
    }
    return 0;
}