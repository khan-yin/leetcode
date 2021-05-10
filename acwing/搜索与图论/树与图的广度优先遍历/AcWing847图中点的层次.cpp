#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 100010;
const int M = 2*N;



int head[N],e[M],ne[M],idx;
bool isvisited[N];
int d[N];

void add(int a,int b)
{
    e[idx] = b, ne[idx] = head[a], head[a] = idx++; 
}


void bfs(int x)//节点编号
{
    d[x]=0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int node = q.front();
        // cout<<q.size()<<endl;
        q.pop();
        for(int i = head[node];i!=-1;i=ne[i])
        {
            int nextnode = e[i];
            if(d[nextnode]==-1)
            {
                q.push(nextnode);
                d[nextnode] = d[node] + 1;
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    memset(head,-1,sizeof head);
    memset(d,-1,sizeof(d));
    while(m--)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        add(a,b);//有向图
    }
    bfs(1);
    cout<<d[n]<<endl;
    
    return 0;
}