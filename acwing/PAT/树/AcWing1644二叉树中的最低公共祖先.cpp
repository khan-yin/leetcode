// PAT甲级真题1151
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 10010;
int n,m;

unordered_map<int,int> pos;
int in[N],pre[N],seq[N];
int p[N],depth[N];

int build(int il,int ir,int pl,int pr,int d)
{
    int root = pre[pl];
    int k = root;
    
    depth[root] = d;
    
    if(il<k)
    {
        int Lroot = build(il,k-1,pl+1,pl+1+k-1-il,d+1);
        p[Lroot] = root;
    }
    if(k<ir)
    {
        int Rroot = build(k+1,ir,pl+1+k-1-il+1,pr,d+1);
        p[Rroot] =  root;
    }
    
    return root;
    
}


int main()
{
    scanf("%d%d", &m, &n);
    
    for(int i=0;i<n;i++) 
    {
        scanf("%d", &seq[i]);
        pos[seq[i]] = i;
        in[i] = i;
    }
    

    for(int i=0;i<n;i++)
    {
        scanf("%d", &pre[i]);
        pre[i] = pos[pre[i]];
    }
    
    build(0,n-1,0,n-1,0);
    
    while (m -- )
    {
        int a,b;
        scanf("%d%d", &a, &b);
        
        if(pos.count(a) && pos.count(b))
        {
            a = pos[a];
            b = pos[b];
            int x=a,y=b;
            while(a!=b)
            {
                // p[a]<p[b]则说明b更深
                if(depth[a]<depth[b]) b =p[b];
                else a = p[a];
            }
            if(a!=x&&a!=y) printf("LCA of %d and %d is %d.\n",seq[x],seq[y],seq[a]);
            else if(a==x) printf("%d is an ancestor of %d.\n",seq[x],seq[y]);
            else printf("%d is an ancestor of %d.\n",seq[y],seq[x]);
        }
        else if(!pos.count(a) && !pos.count(b))
        {
            printf("ERROR: %d and %d are not found.\n",a,b);
        }
        else if(!pos.count(a))
        {
            printf("ERROR: %d is not found.\n",a);
        }
        else
        {
            printf("ERROR: %d is not found.\n",b);
        }

    }
    
    return 0;
}