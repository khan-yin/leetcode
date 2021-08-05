#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =  graph.size();
        queue<int> q;
        vector<int> in(n,0);
        vector<int> out(n,0);
        vector<vector<int>> rg(n);
        for(int i=0;i<n;i++)
        {
            for(auto j : graph[i])
            {
                rg[j].push_back(i);
                in[i]++;
            }
        }

        for(int i=0;i<n;i++) if(in[i]==0) q.push(i);

        vector<int> res;
        while(q.size())
        {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for(auto& j : rg[t])
            {
                in[j]--;
                if(in[j]==0) q.push(j);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};