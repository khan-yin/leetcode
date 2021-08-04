// PAT甲级真题1076
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e3 + 20, M = 2e4 + 10, inf = 0x3f3f3f3f;

bool vis[N];
vector<int> graph[N];

int n,l;


int bfs(int x)
{
    memset(vis,0,sizeof vis);
    queue<int> q;
    int res = 0;
    q.push(x);
    vis[x]=true;
    int cnt=0;
    for(int s=0;s<l;s++)
    {
        int sz = q.size();
        res += sz;
        for (int i = 0; i < sz; i ++ )
        {
            int t = q.front();
            q.pop();
            for(auto item : graph[t]) 
            {
                if(!vis[item])
                {
                    vis[item]=true;
                    cnt++;
                    q.push(item);
                }
            }
        }
    }


    return cnt;
}

int main()
{
    scanf("%d%d", &n, &l);
    for(int i = 1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        while (m -- )
        {
            int x;
            scanf("%d", &x);
            graph[x].push_back(i);

        }
    }


    int k;
    scanf("%d", &k);
    while (k -- )
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", bfs(x));
    }

    return 0;
}