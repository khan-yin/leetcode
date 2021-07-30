// PAT甲级真题1102
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


const int N = 30;
int n;
int l[N], r[N];
bool has_father[N];
int q[N];

void swapdfs(int x)
{
    if(l[x]>=0) swapdfs(l[x]);
    if(r[x]>=0) swapdfs(r[x]);
    // cout<<x<<" "<<l[x]<<" "<<r[x]<<endl;
    swap(l[x],r[x]);
}

void dfs(int x,int& k)
{
    if(l[x]>=0) dfs(l[x],k);
    cout<<x;
    if(++k !=n) cout<<' ';
    if(r[x]>=0) dfs(r[x],k);
}

void bfs(int x)
{
    int hh = 0, tt = 0;
    q[0]=x;
    while(hh<=tt)
    {
        int t = q[hh++];
        if(t!=x) cout<<' ';
        cout<<t;
        if(l[t]>=0) q[++tt]=l[t];
        if(r[t]>=0) q[++tt]=r[t];
    }
}

int main()
{
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        char a,b;
        cin>>a>>b;
        // cout<<a<<" "<<b<<endl;
        if(a!='-')
        {
            l[i] = a-'0';
            has_father[l[i]]=true;
        }
        if(b!='-')
        {
            r[i] = b-'0';
            has_father[r[i]]=true;
        }
    }
    
    int i;
    for(i=0;i<n;i++) if(has_father[i]==false) break;
    int root = i;
    // dfs(root);
    // cout<<endl;
    swapdfs(root);
    bfs(root);
    cout<<endl;
    int k=0;
    dfs(root,k);
    cout<<endl;
    
    
    return 0;
}
