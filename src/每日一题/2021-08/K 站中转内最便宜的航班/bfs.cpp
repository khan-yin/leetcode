#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int g[110][110];
    int dist[110];
    bool vis[110];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto item : flights)
        {
            int from = item[0];
            int to = item[1];
            g[from][to] = item[2];
        }

        queue<pair<int,int>> q;
        q.push({src,0});
        memset(dist,0x3f,sizeof dist);
        
        int m = k+1;
        while(m--)
        {
            int sz = q.size();
            // cout<<sz<<endl;
            while(sz--)
            {   
                auto t = q.front();
                int node = t.first;
                int dis = t.second;
                q.pop();
                // cout<<node<<' '<<dis<<endl;
                for(int i=0;i<n;i++)
                {
                    if(g[node][i]&&dist[i]>dis+g[node][i])
                    {
                        dist[i] = dis+g[node][i];
                        q.push({i,dist[i]});
                    }
                }
            }   
        }
        if(dist[dst]==0x3f3f3f3f) return -1;
        return dist[dst];
    }
};