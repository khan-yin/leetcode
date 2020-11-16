package 深度优先搜索专题.水域大小;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {
    public int row;
    public int column;
    public List<Integer> arr = new ArrayList<>();
    public boolean[][] isvisited;

    public int dfs(int[][] land, int center_row, int center_column) {
        if (center_row < 0 || center_row >= row || center_column < 0 || center_column >= column) {
            return 0;
        } else if (land[center_row][center_column] != 0 || isvisited[center_row][center_column] == true) {
            return 0;
        }
        isvisited[center_row][center_column] = true;

        return dfs(land, center_row - 1, center_column - 1)
                + dfs(land, center_row - 1, center_column)
                + dfs(land, center_row - 1, center_column + 1)
                + dfs(land, center_row, center_column - 1)
                + dfs(land, center_row, center_column + 1)
                + dfs(land, center_row + 1, center_column - 1)
                + dfs(land, center_row + 1, center_column)
                + dfs(land, center_row + 1, center_column + 1) + 1;
    }


    public int[] pondSizes(int[][] land) {
        if (land == null)
            return null;
        row = land.length;
        column = land[0].length;

        this.isvisited = new boolean[row][column];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (land[i][j] == 0 && isvisited[i][j] == false) {
                    int water = dfs(land, i, j);
                    arr.add(water);
                }
            }
        }
        Collections.sort(arr);
        int[] as = arr.stream().mapToInt(Integer::valueOf).toArray();//ArrayList转int[]
        return as;
    }
}
