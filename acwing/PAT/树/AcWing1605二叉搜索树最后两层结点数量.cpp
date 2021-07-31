// PAT甲级真题1115
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N];
int l[N],r[N],v[N],idx;
int cnt[N],max_depth;

void insert(int& u,int w)
{
    if(!u)
    {
        u = ++idx;
        v[u] = w;
    }
    else if(w<=v[u])
    {
        insert(l[u],w);
    }
    else
    {
        insert(r[u],w);
    }
}


void dfs(int root,int depth)
{
    if(!root)
    {
        return;
    }
    max_depth = max(depth,max_depth);
    cnt[depth]++;
    dfs(l[root],depth+1);
    dfs(r[root],depth+1);
    
}


int main()
{
    int n;
    int root=0;
    scanf("%d", &n);
    sort(a,a+n);
    for(int i=1;i<=n;i++)
    {
        int w;
        cin>>w;
        insert(root,w);
    }
    
    dfs(root,0);
    
    
    cout<<cnt[max_depth]<<" + "<<cnt[max_depth-1]<<" = "<<cnt[max_depth]+cnt[max_depth-1]<<endl;
    
    return 0;
}