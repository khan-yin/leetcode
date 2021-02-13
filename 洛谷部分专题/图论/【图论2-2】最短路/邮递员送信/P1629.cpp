#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct Edge{
    int w;
    int to;
    int next;
};

int head[205];
int fhead[205];
Edge edge[100005];
Edge fedge[100005];
int cnt;
int fcnt;
int dist[100005];
int fdist[100005];
bool isvist[205];//区分已经优化的node和未优化的node
bool fisvist[205];

int n,m;//城市的节点数量，道路数量

void add_edge(int u,int v,int w)
{
    edge[cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void fadd_edge(int u,int v,int w)
{
    fedge[fcnt].w=w;
    fedge[fcnt].to=v;
    fedge[fcnt].next=fhead[u];
    fhead[u]=fcnt++;
}

struct node
{
    int dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

priority_queue<node> q;
priority_queue<node> fq;

void dijstra(int start)
{
    dist[start]=0;
    q.push((node){0,start});
    
    while(!q.empty())
    {
        node temp = q.top();
        int pos =temp.pos;
        int dis = temp.dis;
        if(isvist[pos])
            continue;
        isvist[pos]=true;
        q.pop();
        for(int i=head[pos];i!=-1;i=edge[i].next)
        {
            int j = edge[i].to;
            if(dist[j]>dist[pos]+edge[i].w)
            {
                dist[j]=dist[pos]+edge[i].w;
                if(!isvist[j])
                    q.push((node){dist[j],j});
            }
        }
    }
}

void fdijstra(int start)
{
    fdist[start]=0;
    fq.push((node){0,start});
    while(!fq.empty())
    {
        node temp = fq.top();
        int pos =temp.pos;
        int dis = temp.dis;
        if(fisvist[pos])
            continue;
        fisvist[pos]=true;
        fq.pop();
        for(int i=fhead[pos];i!=-1;i=fedge[i].next)
        {
            int j = fedge[i].to;
            if(fdist[j]>fdist[pos]+fedge[i].w)
            {
                fdist[j]=fdist[pos]+fedge[i].w;
                if(!fisvist[j])
                    fq.push((node){fdist[j],j});
            }
        }
    }
}


int main()
{
    long long ans=0;
    memset(head, -1, sizeof(head));
    memset(fhead, -1, sizeof(fhead));
    cin>>n>>m;
    //定义最大值。注意不要设0x7fffffff, 加的时候会爆int 
    for(int i = 0; i <= m; ++i)
        dist[i] =99999999;
    for(int i = 0; i <= m; ++i)
        fdist[i] = 99999999;
    
    for(int i=1;i<=m;i++)
    {
        int from,to,w;
        scanf("%d %d %d",&from,&to,&w);
        add_edge(from,to,w);
        fadd_edge(to,from,w);
    }

    dijstra(1);
    fdijstra(1);
    for(int i = 2; i <= n; ++i) 
    {
        ans = ans +dist[i]+fdist[i];
    }
    cout<<ans<<endl;
    return 0;
}