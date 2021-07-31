// PAT甲级真题1066
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 40;

int l[N],r[N],v[N],h[N],idx;
int n;

//更新节点的高度
void update(int u)
{
    h[u] = max(h[l[u]],h[r[u]])+1;
}


int getbalance(int u)
{
    return h[l[u]] - h[r[u]];
}


void R(int& u)
{
    int p = l[u];
    l[u] = r[p];
    r[p] = u;
    update(u);
    update(p);
    u = p;
}

void L(int& u)
{
    int p = r[u];
    r[u] = l[p];
    l[p] = u;
    update(u);
    update(p);
    u = p;
}



void insert(int& u,int w)
{
    if(!u)
    {
        u = ++idx;
        v[u] = w;
    }
    else if(w<v[u])
    {
        insert(l[u],w);
        if(getbalance(u)==2) // 左子树比右子树高2
        {
            if(getbalance(l[u])==1) R(u);
            else  L(l[u]), R(u);

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


int main()
{
    scanf("%d", &n);
    int root = 0;
    for(int i=0;i<n;i++)
    {
        int w;
        scanf("%d", &w);
        insert(root,w);   
    }

    cout<<v[root]<<endl;
    return 0;
}
