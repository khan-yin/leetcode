#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Dist {
    int x, y, z;
    Dist(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
    bool operator< (const Dist& that) const {
        return z > that.z;
    }
};

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        priority_queue<Dist> q;
        vector<int> seen(m * n);
        vector<int> dist(m * n, INT_MAX);
        q.emplace(0, 0, 0);
        dist[0] = 0;
        while (!q.empty()) {
            auto [x, y, z] = q.top();
            q.pop();
            if (seen[x * n + y]) {
                continue;
            }
            seen[x * n + y] = 1;
            dist[x * n + y] = z;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny]) {
                    q.emplace(nx, ny, max(z, abs(heights[x][y] - heights[nx][ny])));
                }
            }
        }
        return dist[m * n - 1];
    }
};

// 作者：zerotrac2
// 链接：https://leetcode-cn.com/problems/path-with-minimum-effort/solution/zui-xiao-ti-li-xiao-hao-lu-jing-by-zerotrac2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。