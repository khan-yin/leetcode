#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int dis;
    int to;
    int next;//上一条边
};

struct node
{
    int start;//起点
    int dis;//距离

    bool operator <(const node &x) const 
    {
        return (x.dis<dis);
    }
};




bool visit[100005];
edge e[200005];
int dis[200005];
int head[100005];
int cnt=0;
priority_queue<node> p;

inline void addedge(int h,int t, int d)
{
    cnt++;
    e[cnt].dis=d;
    e[cnt].to=t;
    e[cnt].next=head[h];
    head[h]=cnt;
}


inline void dijstra(int start)
{
        dis[start]=0;
        p.push((node){start,0});
        while(!p.empty())
        {
            node temp=p.top();
            p.pop();
            int x=temp.start;
            int d=temp.dis;
            if(visit[x])
                continue;
            visit[x]=true;
            for(int i=head[x];i;i=e[i].next)
            {
                int y=e[i].to;
                if(dis[y]>dis[x]+e[i].dis)
                {
                    dis[y]=dis[x]+e[i].dis;
                    if(!visit[y])
                    {
                        p.push((node){y,dis[y]});
                    }
                    
                }
                   
            }
        }
}



int main()
{
    
    int n,m,s;
    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=m;i++) dis[i]=0x7fffffff;
    for(int i=1;i<=m;i++)
    {
        int h,t,d;
        scanf("%d %d %d",&h,&t,&d);
        addedge(h,t,d);
    }
    dijstra(s);
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }



    return 0;
}