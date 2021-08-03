// PAT甲级真题1134
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010 ;
const int M = 100010;

int n,m;
struct Edge
{
    int x;
    int y;
}e[M];

bool vis[N];

int nodes[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d", &e[i].x, &e[i].y);
    }

    int k;
    scanf("%d", &k);

    for(int i=0;i<k;i++)
    {
        memset(vis,0,sizeof vis);
        int cnt;
        scanf("%d", &cnt);
        for(int j=0;j<cnt;j++)
        {
            int a;
            scanf("%d", &a);
            vis[a]=true;
        }
        bool flag = true;
        for(int j=0;j<m;j++)
        {
            if(!vis[e[j].x] && !vis[e[j].y])
            {
                flag=false;
                break;
            }
        }

        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}