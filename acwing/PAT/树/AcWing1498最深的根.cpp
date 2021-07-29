// PAT甲级真题1021
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10100;
const int M =  2*N +10;

int h[N],e[M],ne[M],idx;
int p[N],d[N];
int n;
int maxdepth=0;

void add(int a,int b)
{
    e[idx] =b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

//以当前节点为根节点的子树的深度
//由于是无向图，所以为了防止节点倒回原来的节点，故设置了father用来记录当前节点的访问来源
int getdepth(int x,int father)
{
    // cout<<"father"<<father<<" node"<<x<<endl;
    int depth = 0;
    for(int i = h[x];~i;i=ne[i]) 
    {
        int to = e[i];
        if(to==father) continue;
        depth = max(depth,getdepth(to,x)+1);
    }
    return depth;
}



int  main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i=1;i<=n;i++) p[i]=i;
    
    int k = n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
        if (find(a) != find(b))
        {
            k -- ;
            p[find(a)] = find(b);
        }
    }
    
    
    if(k>1)
    {
        printf("Error: %d components",k);
    }
    else
    {
        int maxd = 0;
        // d[5] = getdepth(5,-1);
        // cout<<d[5]<<endl;
        for(int i=1;i<=n;i++)
        {
            d[i] = getdepth(i,-1);
            // cout<<d[i]<<endl;
            maxd = max(maxd,d[i]);
        }
        // cout<<maxd;
        for(int i=1;i<=n;i++)
            if(maxd == d[i]) cout<<i<<endl;
        
    }
    return 0;
}