#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int row,col;
    bool vis[110][110]={0};
    int cnt = 0;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool flag=true;
    void dfs(int x,int y,vector<vector<int>>& grid)
    {
        vis[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //说明当前节点(x,y)是一个边界点，则说明不满足封闭
            if(nx<0 || nx>=row || ny<0 || ny>=col) 
                flag=false;
            if(nx<0 || nx>=row || ny<0 || ny>=col || vis[nx][ny] || grid[nx][ny]==1)
                continue;
            dfs(nx,ny,grid);
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                //遍历陆地
                if(!vis[i][j]&&grid[i][j]==0)
                {
                    flag=true;
                    dfs(i,j,grid);
                    if(flag) cnt++;
                }
            }
        }
        return cnt;
    }
};