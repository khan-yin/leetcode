#include<algorithm>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
//Hierholzer 算法用于在连通图中寻找欧拉路径，其流程如下：

// 1.从起点出发，进行深度优先搜索。

// 2.每次沿着某条边从某个顶点移动到另外一个顶点的时候，都需要删除这条边。

// 3.如果没有可移动的路径，则将所在节点加入到栈中，并返回。

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> nodemap;

    vector<string> route;

    void dfs(const string& node) {
        while(nodemap.count(node)&&nodemap[node].size()>0)
        {
            string temp=nodemap[node].top();
            nodemap[node].pop();
            dfs(move(temp));
        }
        route.emplace_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it:tickets)
        {
            nodemap[it[0]].emplace(it[1]);
        }

        dfs("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
};