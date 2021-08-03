// PAT甲级真题1131
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#define x first
#define y second


using namespace std;

typedef pair<int, int> PII;


const int N = 100010, M = 2000010;
const int inf = 0x3f3f3f3f;

bool vis[N];
int dist[N],cnt[N];
int h[N],e[M],ne[M],line[M],w[M],idx;
int stops[N];
string info[N];
int pre[N];
int n,m;

string get_number(int x)
{
    char res[5];
    sprintf(res, "%04d", x);
    return res;
}

void add(int a,int b,int c,int lineid)
{
    // cout<<a<<' '<<b<<" "<<c<<' '<<lineid<<endl;
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    line[idx] = lineid;
    h[a] = idx++;
}


void dijkstra(int start,int end)
{
    memset(vis,0,sizeof vis);
    memset(dist,inf,sizeof dist);
    memset(cnt, inf, sizeof cnt);
    priority_queue<PII,vector<PII>,greater<PII>> q;
    dist[start] = 0;
    cnt[start] = 0;
    q.push({dist[start],start});

    while(q.size())
    {
        auto t = q.top();
        q.pop();
        int dis = t.first;
        int node = t.second;
        if(vis[node]) continue;
        vis[node] = true;

        for(int i=h[node];~i;i=ne[i])
        {
            int to = e[i];
            if(vis[to]) continue;

            if(dist[to] > dis + w[i])
            {
                dist[to] = dis + w[i];
                cnt[to] = cnt[node] + 1;
                pre[to] = node;
                info[to] = "Take Line#" + to_string(line[i]) + " from " + 
                    get_number(node) + " to " + get_number(to) + ".";
                q.push({dist[to],to});
            }
            else if(dist[to] == dis + w[i])
            {
                if(cnt[to] > cnt[node] + 1)
                {
                    cnt[to] = cnt[node] + 1;
                    pre[to] = node;
                    info[to] = "Take Line#" + to_string(line[i]) + " from " + 
                    get_number(node) + " to " + get_number(to) + ".";
                }
            }
        }

    }

    cout << dist[end] << endl;
    vector<string> path;
    for (int i = end; i != start; i = pre[i])
        path.push_back(info[i]);

    for (int i = path.size() - 1; ~i; i -- )
        cout << path[i] << endl;

}



int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);

    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d", &m);
        for(int j=0;j<m;j++) scanf("%d", &stops[j]);

        for (int j = 0; j < m; j ++ )
            for (int k = 0; k < j; k ++ )
            {
                int len;
                if(stops[0]!=stops[m-1]) len = j - k;
                else len = min(j - k, m - 1 - j + k);
                add(stops[j],stops[k],len,i);
                add(stops[k],stops[j],len,i);
                // break;
            }
    }

    int k;
    scanf("%d", &k);

    while(k--)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        // cout<<x<<y<<endl;
        dijkstra(x,y);
    }

    return 0;
}