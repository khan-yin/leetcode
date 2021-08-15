#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int px[4]={-1,1,0,0};
    int py[4]={0,0,1,-1};
    int vis[55][55][55]; // vis[i][j][k] 从(i,j)位置在k步内出界的路径数
    int mod = 1e9+7;
    int m;
    int n;
    int dfs(int x,int y,int move)
    {
        if(x<0 || x>=m || y<0 || y>=n ) return 1;
        if(move==0) return 0;
        if(vis[x][y][move]!=-1) return vis[x][y][move];
        int ans = 0;
        for(int i=0;i<4;i++)
        {
            int nx = x +px[i];
            int ny = y + py[i];
            ans += dfs(nx,ny,move-1);
            ans %= mod;
        }

        vis[x][y][move] = ans;
        return ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(vis,-1,sizeof vis);
        this->m = m;
        this->n = n;
        return dfs(startRow,startColumn,maxMove) % mod;
    }


};