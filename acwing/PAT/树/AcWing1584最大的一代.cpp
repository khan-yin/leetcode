// PAT甲级真题1094
#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include<string>
#include<vector>

using namespace std;

const int N = 200;
int n,m;

int g[N][N];
int q[N];
int cnt[N];

int depth,maxdepth;
int maxnode;


void bfs()
{
    int head = 0;
    int tail = 0;
    q[0] = 1;

    while(head<=tail)
    {
        int h = head;
        int t = tail;
        depth++;
        while(head<=t)
        {
            int node = q[head++];
            // cout<<node<<" ";
            cnt[depth]++;
            for(int i=1;i<=n;i++)
            {
                if(g[node][i]) q[++tail] = i;
            }
        }
        if(maxnode<cnt[depth])
        {
            maxnode = cnt[depth];
            maxdepth = depth;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m); 
    
    for(int i=0;i<m;i++)
    {
        int id,k;
        scanf("%d%d", &id, &k);
        for(int j=0;j<k;j++)
        {
            int to;
            scanf("%d", &to);
            g[id][to] = 1;
        }
    }
    bfs();
    // cout<<endl;
    
    cout<<maxnode<<' '<<maxdepth;
        
    return 0;
}