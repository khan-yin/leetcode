// PAT甲级真题1004
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int h[N],e[N],ne[N],cnt[N],idx;
int max_depth=0;

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


void dfs(int x,int depth)
{
    //说明是叶子节点
    if(h[x]==-1)
    {
        cnt[depth]++;
        max_depth = max(max_depth,depth);
        return;
    }
    
    for(int i=h[x];~i;i=ne[i])
    {
        dfs(e[i],depth+1);
    }
}

int main()
{
    int n,m;
    scanf("%d%d", &n,&m);
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a,b;
        int c;
        cin>>a>>c;
        while(c--) 
        {
            cin>>b;
            add(a,b);
        }
    }
    
    dfs(1,0);
    cout<<cnt[0];
    for(int i=1;i<=max_depth;i++) cout<<" "<<cnt[i];
    
    return 0;
}