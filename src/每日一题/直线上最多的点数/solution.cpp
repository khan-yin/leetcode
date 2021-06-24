#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(len<3) return len;
        int ans = 0;
        for(int i=0;i<len;i++)
        {
            unordered_map<double,int> m;
            for(int j=0;j<len;j++)
            {
                if(i==j) continue;
                long long x1 = points[i][0];
                long long y1 = points[i][1];
                long long x2 = points[j][0];
                long long y2 = points[j][1];
                double gradient = (y2 - y1) *1.0 / (x2 - x1);
                if(m.count(gradient))
                    m[gradient]++;
                else 
                    m[gradient]=2;
                ans = max(ans,m[gradient]);
            }
        }
        return ans;
    }
};