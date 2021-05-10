#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;


const int N = 200010;
//稀疏图按邻接表存储

int n,m;

int head[N],e[N],ne[N],w[N],idx; //head[]是邻接表，e[]存储当前边指向的终点，ne[]表示下一条边的编号，w存储边权值，idx记录边的数量

int dist[N];
bool isvisited[N];

void add(int x,int y,int z)
{
    e[idx] = y, ne[idx] = head[x], w[idx] = z, head[x] = idx ++;
}


int dijkstra(int x)
{
    memset(dist, 0x3f, sizeof dist); //初始化dist数组为无穷大
    priority_queue<PII, vector<PII>, greater<PII>> heap;//小根堆作为dist，存储节点的最短距离
    //如果不用pair也可以自定义结构体
    heap.push({0,x});//(dist：距离，节点)这个顺序不能倒! 这里需要距离排序 pair排序时是先根据first，再根据second，
    dist[x]=0;//起点距离为0
    
    while(heap.size())
    {
        auto t = heap.top();//弹出堆顶元素,即最近的距离，可能是已经被访问的节点
        heap.pop();
        int node = t.second, distance = t.first;

        if(isvisited[node]) continue; //如果是已经被访问的节点则直接跳过
        
        isvisited[node]=true;//标记

        //更新dist数组
        for(int i = head[node];i!=-1;i=ne[i])
        {
            int endnode = e[i];//边的终点
            if(dist[endnode] > distance + w[i])
            {
                dist[endnode] = distance + w[i];
                heap.push({dist[endnode],endnode});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof head); //初始化所有的邻接表
    while (m -- )
    {
        int x,y,z;
        scanf("%d%d%d", &x, &y,&z);
        add(x,y,z);//对于邻接表可以不处理重边的问题
    }
    cout<<dijkstra(1)<<endl;
    return 0;
}