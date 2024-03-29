#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 100010;
class Solution {
public:
    
    int q[N];//q[i]表示长度为i的最长上升子序列的结尾的数的最小值
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp(n);
        
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;
        }
        
        int len = 0;
        
        q[0] = obstacles[0];
        
        for(int i=0;i<n;i++)
        {
            int l = 0, r = len;
            while(l<r)
            {
                int mid = l + r + 1 >> 1;
                if(q[mid]<=obstacles[i]) l = mid;
                else r = mid -1;
            }
            len = max(len,l+1);
            q[l+1] = obstacles[i];
            dp[i] = l+1;
        }

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
                
//                 if(obstacles[j]<=obstacles[i]) dp[i] = max(dp[j]+1,dp[i]);
//             }
//         }
        return dp;
    }
};