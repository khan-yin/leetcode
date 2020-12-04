#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
//二分+dfs方法

class Solution {
public:
    // static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int h;
    int w;
public:
    bool dfs(vector<vector<bool>>& isvisted,vector<vector<int>>& heights,int x,int y,int maxh)
    {
        if(x==h-1&&y==w-1)
            return true;
        isvisted[x][y]=true;
        // cout<<x<<" "<<y<<endl;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=h||ny<0||ny>=w||isvisted[nx][ny])
                continue;
            int minus=abs(heights[x][y]-heights[nx][ny]);
            // cout<<minus<<endl;
            if(minus>maxh)
                continue;
            bool res=dfs(isvisted,heights,nx,ny,maxh);
            // cout<<res<<endl;
            if(res) return true;
        }
        return false;
        
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->h=heights.size();
        this->w=heights[0].size();

        int left = 0, right = 1e6, mid, ans = 0;
        bool flag=false;
        while(left<=right)
        {
            mid = left + ((right-left)>>1);
            // cout<<mid<<endl;
            vector<vector<bool>> isvisted(h, vector<bool>(w,false));
            if(dfs(isvisted, heights, 0, 0, mid))
            {
                right=mid-1;
                ans=mid;
            }
            else
                left = mid+1;
        }
        return ans;
    }
};