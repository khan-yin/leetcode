#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int v=1;
        double s = -1;
        if(n-1>hour) return -1;
        for(v=1;v<1e7;v++)
        {
            s = hour;
            for(int i=0;i<n-1;i++)
            {
                int t = ceil(dist[i]*1.0/v);
                s-=t;
            }
            double t = dist[n-1]*1.0/v;
            s -=t;
            if(s>=0) break;
        }
        return v;
    }
};