// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<set>
#include<queue>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int length=graph.size();
        vector<int> enter(length,0);
        vector<set<int>> regraph(length,set<int>());
        queue<int> q;
        vector<int> res;
        if(length==1)
        {
            res.push_back(0);
            return res;
        }
        for(int i=0;i<length;i++)
        {
            if(graph[i].empty())
            {
                q.push(i);
            }
            for(auto node : graph[i])
            {
                enter[i]++;
                regraph[node].insert(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(enter[node]==0)
            {
                res.push_back(node);
            }
            for(auto neighbor:regraph[node])
            {
                enter[neighbor]--;
                if(enter[neighbor]==0)
                    q.push(neighbor);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

