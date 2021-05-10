#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int head[N],e[N],ne[N],idx;
int d[N];//入度
int n,m;
int q[N];

void add(int a,int b)
{
    e[idx] = b, ne[idx] = head[a], head[a] = idx++;
}

bool toposort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
    {
        if(!d[i]) q[++tt]=i; //入度为0的点加入队列
    }
    
    while(hh<=tt)
    {
        int t = q[hh++]; // 弹出一个入度为0的点
        for(int i = head[t];i!=-1;i=ne[i])
        {
            int nextnode = e[i];
            d[nextnode]--;//入度--
            if(!d[nextnode]) q[++tt]=nextnode; 
        }
    }
    
    return tt == n-1;
    
}



int main()
{
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof head);
    while (m -- )
    {
        int a,b;
        scanf("%d%d", &a, &b);
        add(a,b);//有向图
        d[b]++;//入度++
    }
    
    if(toposort())
    {
        for(int i=0;i<n;i++) cout<<q[i]<<" ";
        cout<<endl;
    }
    else
        cout<<-1<<endl;
    
    return 0;
}