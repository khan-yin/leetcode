package 每日一题.岛屿的周长;

public class Solution {
    public int column;
    public int row;

    public int islandPerimeter(int[][] grid) {
        row = grid.length;
        column = grid[0].length;
        int total = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == 1) {
                    total += count_around(grid, i, j);
                }
            }
        }
        return total;
    }

    public int count_around(int[][] grid, int center_row, int center_column) {
        int cnt = 0;
        int up = center_row - 1;
        int down = center_row + 1;
        int left = center_column - 1;
        int right = center_column + 1;
        if (up < 0 || grid[up][center_column] == 0) {
            cnt++;
        }
        if (down >= row || grid[down][center_column] == 0) {
            cnt++;
        }
        if (left < 0 || grid[center_row][left] == 0) {
            cnt++;
        }
        if (right >= column || grid[center_row][right] == 0) {
            cnt++;
        }
        return cnt;
    }
}
