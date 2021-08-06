// PAT甲级真题1118
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int p[N];

int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int vis[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i=1;i<N;i++) p[i]=i;
    
    int cnt =0;
    
    while (n -- )
    {
        int m;
        scanf("%d", &m);
        int a;
        scanf("%d", &a);
        int pa = find(a);
        vis[a]=1;
        for(int i=1;i<m;i++)
        {
            int x;
            scanf("%d", &x);
            int px = find(x);
            vis[x]=1;
            if(px!=pa)
            {
                p[px] =pa;
                cnt++;
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < N; i ++ ) total += vis[i];
    

    printf("%d %d\n",total-cnt,total);
    
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        cout<<(find(a)==find(b) ? "Yes" : "No")<<endl;
    }
    
    
    return 0;
}