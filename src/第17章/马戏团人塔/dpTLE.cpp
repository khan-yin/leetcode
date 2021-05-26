#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct People
{
    int h;
    int w;
    bool operator < (const People & W) const
    {
        if(h==W.h) return w<W.w;
        return h< W.h;
    }
};

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<People> res;
        for(int i=0;i<height.size();i++)
        {
            res.push_back({height[i],weight[i]});
        }
        sort(res.begin(),res.end());
        int* dp = new int[res.size()];
        for(int i=0;i<res.size();i++)
            dp[i]=1;
        int len =0;
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(res[i].h>res[j].h && res[i].w>res[j].w)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            len = max(len,dp[i]);
        }
        
        return len;
    }
};