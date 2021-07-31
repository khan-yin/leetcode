// PAT甲级真题1123
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 40;
int n;
int l[N], r[N], v[N],h[N], idx;
int q[N],pos[N];
int maxid;

void update(int u)
{
    h[u] = max(h[l[u]],h[r[u]])+1;
}

int getbalance(int u)
{
    return h[l[u]] - h[r[u]];
}

void R(int &u)
{
    int p = l[u];
    l[u] = r[p], r[p] = u;
    update(u), update(p);
    u = p;
}


void L(int &u)
{
    int p = r[u];
    r[u] = l[p], l[p] = u;
    update(u), update(p);
    u = p;
}

void insert(int &u,int w)
{
    if(!u)
    {
        u = ++idx;
        v[u] = w;
    }
    else if(w<v[u])
    {
        insert(l[u],w);
        if(getbalance(u)==2)
        {
            if(getbalance(l[u])==1) R(u);
            else L(l[u]), R(u);
        }
    }
    else
    {
        insert(r[u],w);
        if(getbalance(u)==-2)
        {
            if(getbalance(r[u])==-1) L(u);
            else R(r[u]), L(u);
        }
    }
    update(u);
}

bool bfs(int root)
{
    int head=0,tail=0;
    q[0] = root;
    pos[root] = 1;
    bool res = true;
    while(head<=tail)
    {
        int t = q[head++];
        if (pos[t] > n) res = false;
        if(l[t]) q[++tail] = l[t], pos[l[t]] = 2*pos[t];
        if(r[t]) q[++tail] = r[t], pos[r[t]] = 2*pos[t] + 1;
    }
    return res;
}


int main()
{
    scanf("%d", &n);
    int root = 0;
    for(int i=0;i<n;i++)
    {
        int w;
        cin>>w;
        insert(root,w);
    }
    // for(int i=1;i<=n;i++) cout<<i<<' '<<l[i]<<' '<<r[i]<<' '<<v[i]<<endl;
    bool flag = bfs(root);
    
    cout<<v[q[0]];
    for(int i=1;i<n;i++) cout<<' '<<v[q[i]];
    cout<<endl;
    
    if(flag) puts("YES");
    else puts("NO");
    
    
    return 0;
}
