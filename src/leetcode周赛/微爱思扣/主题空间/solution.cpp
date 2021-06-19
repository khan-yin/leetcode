#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool vis[510][510]={0};
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int row,col;
    bool flag;
    int cnt=0;
    void dfs(int x,int y,vector<string>& grid)
    {
        vis[x][y]=true;
        cnt++;
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx >= row || ny<0 || ny>=col || grid[nx][ny]=='0') 
                flag=true;
            if(nx<0 || nx >= row || ny<0 || ny>=col ||vis[nx][ny] || grid[x][y]!=grid[nx][ny]) 
            continue;
            dfs(nx,ny,grid);
        }
    }
    int largestArea(vector<string>& grid) {
        row = grid.size();
        col = grid[0].size();
        int res = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                flag=false;
                if(!vis[i][j])
                {
                    cnt=0;
                    dfs(i,j,grid);
                    if(!flag)
                        res = max(res,cnt);
                }
                // cout<<"m:"<<i<<" "<<j<<vis[i][j]<<endl;
            }
        }
        return res;
    }
};