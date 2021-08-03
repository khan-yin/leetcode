// PAT甲级真题1154
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 10010;
bool vis[N];
int a[N];
int n,m;

struct Edge
{
    int x;
    int y;
}e[N];





int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d", &e[i].x, &e[i].y);
    }
    int k;
    scanf("%d", &k);
    
    while(k--)
    {
        set<int> ans;
        for(int i=0;i<n;i++) 
        {
            scanf("%d", &a[i]);
            ans.insert(a[i]);
        }
        
        bool res=true;
        for(int i=0;i<m;i++) if(a[e[i].x]==a[e[i].y]) { res=false; break; }
        if(res) printf("%d-coloring\n",ans.size());
        else puts("No");
    }
    return 0;
}