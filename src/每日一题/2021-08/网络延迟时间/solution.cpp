#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1010;
const int inf = 0x3f3f3f3f;
class Solution {
public:
    int g[N][N];
    int dist[N];
    bool vis[N];
    int maxtime=0;
    int n;
    void dijstra(int x)
    {
        memset(dist,0x3f,sizeof dist);
        memset(vis,0,sizeof vis);
        int cnt=0;
        dist[x]=0;
        while(cnt<n)
        {
            int t = -1;
            for(int i=1;i<=n;i++)
            {
                if(!vis[i]&& (t==-1 || dist[t] > dist[i])) t = i;
            }
            if(t==-1) break;
            // cout<<t<<endl;
            vis[t]=true;
            for(int i=1;i<=n;i++)
            {
                if(!vis[i])
                {
                    dist[i] = min(dist[i],dist[t]+g[t][i]);
                    
                }
            }
        }

    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        this->n = n;
        memset(g,0x3f,sizeof g);
        for(auto time : times)
        {
            int u = time[0], v= time[1],w = time[2];
            g[u][v]=w;
        }

        dijstra(k);

        for(int i=1;i<=n;i++) 
        {
            // cout<<k<<"-->"<<i<<' '<<dist[i]<<endl;
            maxtime = max(maxtime,dist[i]);
        }
        // int maxtime = *max_element(dist.begin(), dist.end());
        return (maxtime == inf) ? -1 : maxtime;

    }
};