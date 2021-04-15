#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        //初始化第一行和第一列
        for(int i=1;i<column;i++)
            grid[0][i]+=grid[0][i-1];
        for(int i=1;i<row;i++)
            grid[i][0]+=grid[i-1][0];
        
        for(int i=1;i<row;i++)
            for(int j=1;j<column;j++)
                grid[i][j]+=max(grid[i-1][j],grid[i][j-1]);
        
        return grid[row-1][column-1];
    }
};