#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int inf = 0x3f3f3f3f;

    int shortestPathLength(vector<vector<int>>& graph) {
        // memset(dist, inf,sizeof dist);
        int n = graph.size();
        
        int mask = 1 << n;

        vector<vector<int>> dist(1 << n,vector<int>(n));

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            // cout<< dist[1 << i][i]<<endl;
            q.push({1<<i,i,0});
            dist[1 << i][i] = true;
        }

        int ans = 0;
        // bfs
        while(q.size())
        {
            auto [state, node, step] = q.front();
            q.pop();
            
            // cout<<state<<' '<<node<<endl;
            if (state == (1 << n) - 1) {
                ans = step;
                break;
            }

            for(int i : graph[node])
            {
                if (!dist[state | (1 << i)][i])
                {
                    dist[state | (1 << i)][i] = true;
                    q.push({state | (1 << i), i,step + 1});
                } 
            }
        }
        
        return ans;
    }
};