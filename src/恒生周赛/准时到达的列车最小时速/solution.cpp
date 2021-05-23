#include<vector>
using namespace std;

class Solution {
public:
    double getTime(vector<int>& dist,int v)
    {
        int n = dist.size();
        double h = 0;
        for(int i =0;i<n-1;i++)
        {
            //ceil返回的是浮点数可能导致出现精度丢失
            h +=  (dist[i] + v -1) / v; // c++中/默认为下取整 a/b上取整 = a+b-1 / b
        }
        return h + (double)dist[n-1] / v;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=2e7;
        //二分枚举最小速度
        while(l<r)
        {
            int mid = l + r >> 1;
            if(getTime(dist,mid)<=hour){
                r = mid;
            }
            else
                l = mid + 1;
        }
        if(r==2e7) return -1;
        return r;
    }
};