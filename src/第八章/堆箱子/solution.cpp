#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
struct People
{
    int w;
    int d;
    int h;
    bool operator < (const People & W) const
    {
        if(h==W.h) 
        {
            if(w == W.w) return d<W.d;
            return w<W.w;
        }
        return h< W.h;
    }
};

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        vector<People> res;
        for(int i=0;i<box.size();i++)
        {
            res.push_back({box[i][0],box[i][1],box[i][2]});
        }
        sort(res.begin(),res.end());
        int* dp = new int[res.size()];
        for(int i=0;i<res.size();i++)
            dp[i]=res[i].h;
        int len =0;
        for(int i=0;i<res.size();i++)
        {
            // upper_bound()
            for(int j=0;j<i;j++)
            {
                if(res[i].h>res[j].h && res[i].w>res[j].w && res[i].d > res[j].d)
                {
                    dp[i]=max(dp[i],dp[j]+res[i].h);
                }
            }
            len = max(len,dp[i]);
        }
        
        return len;
    }
};

