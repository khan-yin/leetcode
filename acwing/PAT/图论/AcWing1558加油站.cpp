// PAT甲级真题1072
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>


using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 20, M = 2e4 + 10, INF = 0x3f3f3f3f;

int n, k, m, dmax;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];

int minway = -1;
int minsum;
int minid;
int mindis;
int sum;


inline int get(string s)
{
    if (s[0] == 'G') return n + stoi(s.substr(1));
    return stoi(s);
}


void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dijkstra(int x)
{
    
    memset(vis,0,sizeof vis);
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII>> q;
    dist[x] = 0;
    q.push({dist[x],x});
    
    while(q.size())
    {
        auto t = q.top();
        q.pop();
        int node = t.second;
        if(vis[node]) continue;
        vis[node] = true;
        for(int i=h[node];~i;i=ne[i])
        {
            int to = e[i];
            if(vis[to]) continue;
            if(dist[to] > dist[node] + w[i])
            {
                dist[to] = dist[node] + w[i];
                q.push({dist[to],to});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if (dist[i] > dmax) return false;
        if (dist[i] < mindis) mindis = dist[i];
        sum += dist[i];
    }
    
    return true;
}


int main()
{
    scanf("%d%d%d%d", &n, &m,&k,&dmax);
    memset(h, -1, sizeof h);
    string a,b;
    int w;
    int x,y;
    while(k--)
    {
        cin>>a>>b>>w;
        x = get(a);
        y = get(b);
        add(x,y,w);
        add(y,x,w);
    }

    for (int i = 1 + n; i <= m + n; i ++ )
    {
        mindis = INF, sum = 0;
        if (dijkstra(i))
        {
            if(mindis > minway)
            {
                minway = mindis;
                minsum = sum;
                minid = i;
            }
            else if(mindis==minway && sum < minsum)
            {
                minsum = sum;
                minid = i;
            }
        }
    }
    
    if (minway>-1)
    {
        printf("G%d\n", minid - n);
        printf("%.1lf %.1lf\n", (double)minway, (double)minsum / n + 1e-8);
    }
    else printf("No Solution");

    return 0;
}

// 玄学TLE
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <queue>

// using namespace std;

// typedef pair<int, int> PII;

// const int N = 1e3 + 20, M = 2e4 + 10;
// const int inf = 0x3f3f3f3f;

// int n,m,k,dmax;

// bool vis[N];
// int dist[N];

// int h[N],e[M],ne[M],w[N],idx;

// int minway = -1;
// int minsum;
// int minid;
// int mindis;
// int sum;

// inline int get(string s)
// {
//     if (s[0] == 'G') return n + stoi(s.substr(1));
//     return stoi(s);
// }


// void add(int a, int b, int c)
// {
//     e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
// }

// bool dijkstra(int x)
// {
//     memset(vis,0,sizeof vis);
//     memset(dist, 0x3f, sizeof dist);
//     priority_queue<PII,vector<PII>,greater<PII>> q;
//     dist[x] = 0;
//     q.push({dist[x],x});
    
//     while(q.size())
//     {
//         auto t = q.top();
//         q.pop();
//         int node = t.second;
//         if(vis[node]) continue;
//         vis[node] = true;
//         // cout<<node<<' '<<dist[node]<<endl;
//         for(int i=h[node];~i;i=ne[i])
//         {
//             int to = e[i];
//             if(vis[to]) continue;
//             if(dist[to] > dist[node] + w[i])
//             {
//                 dist[to] = dist[node] + w[i];
//                 q.push({dist[to],to});
//             }
//         }
//     }

//     for(int i=1;i<=n;i++)
//     {
//         if(dist[i]>dmax || dist[i]==inf) return false;
//         if (dist[i] < mindis) mindis = dist[i];
//         sum += dist[i];
//     }
    
//     return true;
// }



// int main()
// {
//     scanf("%d%d%d%d", &n, &m,&k,&dmax);
//     memset(h, -1, sizeof h);
//     string a,b;
//     int w;
//     int x,y;
//     while(k--)
//     {
//         cin>>a>>b>>w;
//         x = get(a);
//         y = get(b);
//         add(x,y,w);
//         add(y,x,w);
//     }
    

//     for(int i=n+1;i<=n+m;i++)
//     {
//         mindis = inf;
//         sum = 0;
//         if(dijkstra(i))
//         {
//             if(mindis > minway)
//             {
//                 minway = mindis;
//                 minsum = sum;
//                 minid = i;
//             }
//             else if(mindis==minway && sum < minsum)
//             {
//                 minsum = sum;
//                 minid = i;
//             }
//         }
//     }
    
//     if(minway==-1)
//     {
//         printf("No Solution\n");
//     }
//     else
//     {
//         cout<<'G'<<minid-n<<endl;
//         printf("%.1lf %.1lf\n",(double)minway,(double)minsum*1.0/n + 1e-8);
//     }
    
    
//     return 0;
// }