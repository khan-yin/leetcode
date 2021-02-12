#include<bits/stdc++.h>
#define inf 123456789
#define maxn 5005
#define maxm 200005
using namespace std;

struct Edge
{
    int dis;
    int to;
    int next;
}edge[maxm<<1];

int head[maxn];
bool isvisited[maxn];
int dist[maxn];
int cnt=0;
int tot=0;
int n,m;//节点数，边数
long long ans=0;


void add_edge(int from,int to,int dis)
{
    edge[cnt].to = to;
    edge[cnt].dis = dis;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}

inline long long Prime(int start)
{

    for(int i=1;i<=n;i++)
    {
        if(i!=start)
            dist[i] = inf;
        else
            dist[i] = 0;
    }

    //这里要注意重边，所以要用到min
	for(int i=head[start];i!=-1;i=edge[i].next)
	{
		int j = edge[i].to;
        dist[j] = min(dist[j],edge[i].dis);
	}

    
    while(tot<n-1)
    {
        int minn = inf;
        isvisited[start]=true;
        for(int i =1;i<=n;i++)
        {
            if(!isvisited[i]&&minn>dist[i])
            {
                minn = dist[i];
                start = i;
            }
        }
        ans +=minn;
        // cout<<ans<<endl;
        //枚举now的所有连边，更新dis数组
        for(int i=head[start];i!=-1;i=edge[i].next)
        {
            int j = edge[i].to;
        	if(dist[j]>edge[i].dis&&!isvisited[j])
            {
                dist[j]=edge[i].dis;
            }
		}
        tot++;   
    }

    return ans;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int from ,to,w;
        scanf("%d %d %d",&from,&to,&w);
        add_edge(from,to,w);
        add_edge(to,from,w);
    }
    int start  = 1;
    ans = Prime(start);
    if (ans==inf)
        cout<<"orz"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}