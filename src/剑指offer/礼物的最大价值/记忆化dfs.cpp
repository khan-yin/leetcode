#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int column;
    int row;
    int dp[205][205];
    int dfs(int x,int y,vector<vector<int>>& grid)
    {
        if(x<0||y<0)
            return 0;
        if((x==0&&y==0)||dp[x][y]>0)
            return dp[x][y];
        dp[x][y]= max(dfs(x-1,y,grid),dfs(x,y-1,grid))+grid[x][y];
        return dp[x][y];
    }

    int maxValue(vector<vector<int>>& grid) {
        row = grid.size();
        column = grid[0].size();
        dp[0][0]=grid[0][0];
        return dfs(row-1,column-1,grid);
    }
};