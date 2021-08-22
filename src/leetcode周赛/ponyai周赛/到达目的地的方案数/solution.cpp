#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
class Solution {
public:
    long long g[210][210];
    bool vis[210];
    long long dist[210];
    long long cnt[210];
    int n;
    
    void dijkstra(int x)
    {
        memset(dist, inf, sizeof dist);
        dist[x]=0;
        cnt[x]=1;


        for(int i=0;i<n;i++)
        {
            int t = -1;
            for(int j=0;j<n;j++)
            {
                if(!vis[j] && (t==-1 || dist[t] > dist[j]))
                {
                    t = j;
                }
            }

            if(t==-1) break;
            vis[t] =true;

            for(int j=0;j<n;j++)
            {
                if(!vis[j])
                {
                    if(dist[j] > dist[t] + g[t][j])
                    {
                        dist[j] = dist[t] + g[t][j];
                        cnt[j] = cnt[t];
                    }
                    else if(dist[j] == dist[t] + g[t][j])
                    {
                        cnt[j]= (cnt[j] + cnt[t]) % mod;

                    }
                }
            }
        }
    }
    

    
    int countPaths(int n, vector<vector<int>>& roads) {
        this->n = n;
        memset(g,inf,sizeof g);
        memset(vis,0,sizeof vis);
        memset(cnt,0,sizeof cnt);
        // for(int i=0;i<n;i++) g[i][i]=0;
        for(auto road : roads)
        {
            int x = road[0];
            int y = road[1];
            g[x][y] = g[y][x] = min(g[x][y],1LL*road[2]);
        }
        dijkstra(0);
        // cout<<dist[n-1]<<endl;
        return cnt[n-1] % mod;
        
    }
};