// PAT甲级真题1143
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 10010;

int pre[N],in[N],seq[N];
int p[N],depth[N];
unordered_map<int,int> pos;

int m,n;

// 都只处理下标，值均存储在seq当中
int build(int il,int ir,int pl,int pr,int d)
{
    int root = pre[pl];
    int k = root; // 减少了哈希表查找当前元素在中序当中下标的取pos的操作
    
    depth[root] = d;
    
    if(il<k) 
    {
        int Lroot = build(il,k-1,pl+1,pl+1+k-1-il,d+1);
        p[Lroot] = root;
    }
    if(k<ir)
    {
        int Rroot = build(k+1,ir,pl+1+k-1-il+1,pr,d+1);
        p[Rroot] = root;
    }
    
    return root;
}

int main()
{
    scanf("%d%d", &m, &n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d", &pre[i]);
        seq[i] = pre[i];
    }
    
    sort(seq,seq+n);
    for(int i=0;i<n;i++)
    {
        pos[seq[i]] = i;
        in[i] = i;
    }
    
    // 直接得到当前元素在中序遍历中的下标
    for (int i = 0; i < n; i ++ ) pre[i] = pos[pre[i]];

    
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