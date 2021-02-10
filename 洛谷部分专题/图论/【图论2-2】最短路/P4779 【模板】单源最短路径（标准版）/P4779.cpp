#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MaxN = 100010, MaxM = 200010;

//链式前向星存边
struct Edge{
    int to;
    int next;//表示与第cnt条边同起点的上一条边的储存位置
    int dis;
};

Edge edge[MaxM];
int head[MaxN]; //链式地址 //head[i]表示以i起点的最后一条边的储存位置
int cnt;
int dist[MaxN];
bool isvist[MaxN];//区分已经优化的node和未优化的node

inline void add(int from,int to,int dis)
{
    cnt++; // 本来要初始化为-1,这里我们却可以看到因为cnt先++所以就不需要了,终止就是0
    edge[cnt].to = to;//第cnt条边的终点是to
    edge[cnt].dis = dis;//第cnt条边的权值是dis
    edge[cnt].next = head[from]; //head[i]表示以i起点的最后一条边的储存位置
    head[from]=cnt;
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

priority_queue<node> q;//其实可以直接用api操作他的意思就是排序而已

void dijstra(int start)
{
    dist[start]=0;
    q.push((node){0,start});
    while(!q.empty())
    {
        node temp = q.top();
        q.pop();
        int pos =temp.pos;
        int dis = temp.dis;
        if(isvist[pos])
            continue;
        isvist[pos]=true;
        for(int i=head[pos];i>0;i=edge[i].next)
        {
            int j = edge[i].to;
            if(dist[j] >dist[pos]+edge[i].dis) //在dist[pos]基础上通过i到j 是否比当前的最短dist[j]更短
            {
                dist[j] = dist[pos]+edge[i].dis;
                if(!isvist[j])
                    q.push(node{dist[j],j});
            }
        }
    }
}



int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i = 1; i <= n; ++i)
        dist[i] = 0x7fffffff;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }

    dijstra(s);

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}


