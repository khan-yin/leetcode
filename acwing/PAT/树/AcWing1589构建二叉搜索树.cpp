// PAT甲级真题1099
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

const int N = 110,M=2*N+1;

int h[M], a[N], l[N], r[N];
int q[N];
int n,cnt;

void bfs()
{
    int hh = 0, tt = 0;
    q[0] = 0;
    while(hh<=tt)
    {
        int t = q[hh++];
        if(t!=0) cout<<' ';
        cout<<h[t];
        if(l[t]>0) q[++tt]=l[t];
        if(r[t]>0) q[++tt]=r[t];
    }
}


void dfs(int root)
{
    if(l[root]!=-1) dfs(l[root]);
    h[root] = a[cnt++]; 
    // cout<<root<<"->"<<h[root]<<endl;
    if(r[root]!=-1) dfs(r[root]);
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
    }
    
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a,a+n);
    
    dfs(0);
    bfs();
    return 0;
}