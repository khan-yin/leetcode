#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int column;
    int row;
    int dfs(int x,int y,vector<vector<int>>& grid)
    {
        if(x<0||y<0)
            return 0;
        if(x==0&&y==0)
            return grid[x][y];
        return max(dfs(x-1,y,grid),dfs(x,y-1,grid))+grid[x][y];
    }

    int maxValue(vector<vector<int>>& grid) {
        row = grid.size();
        column = grid[0].size();
        return dfs(row-1,column-1,grid);
    }
};