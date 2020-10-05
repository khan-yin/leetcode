package 第八章.迷路的机器人;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    // public int[] dx={-1,0,1};
    // public int[] dy={-1,0,1};//这里只能向下或者向右，因为这个题目是从左上顶点开始的,而且可以知道这样是最快的路径选择方案。

    List<List<Integer>> route = new ArrayList<>();
    public int lines = 0;  // 行数
    public int columns = 0;  // 列数

    public boolean dfs(int[][] map, boolean[][] isFound, int x, int y) {
        // System.out.println(isFound[x][y]);
        //禁止情况
        if (x < 0 || y < 0 || x >= lines || y >= columns || isFound[x][y] || map[x][y] == 1) {
            // System.out.println(isFound[x][y]);
            return false;
        }
        //可以继续，则添加当前节点
        route.add(Arrays.asList(x, y));
        isFound[x][y] = true;
        // System.out.println(isFound[x][y]);
        //回溯终点
        if (isFound[lines - 1][columns - 1] == true) {
            return true;
        }
        //继续回溯
        //这个写法看似没问题，其实是有问题的，他会在right和down都满足的时候出现不同路径节点交叉的情况，但把这两个写到一个判断语句当中会由于||的短路性而不会出现重叠
        // boolean right=dfs(map,isFound,x,y+1);//向右
        // boolean down=dfs(map,isFound,x+1,y);//向下
        if (dfs(map, isFound, x, y + 1) || dfs(map, isFound, x + 1, y))//说明向下或者向右至少存在一种情况可以到达终点
        {
            return true;
        }
        //到这一步说明向右和向下都没用，所以必须移除这个节点，返回上一步操作并return false
        route.remove(route.size() - 1);
        return false;
    }

    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        this.lines = obstacleGrid.length;
        this.columns = obstacleGrid[0].length;
        // System.out.println(1);
        if (lines == 0 || this.columns == 0 || obstacleGrid[lines - 1][columns - 1] == 1)
            return this.route;
        boolean[][] isFound = new boolean[lines][columns];
        dfs(obstacleGrid, isFound, 0, 0);
        // System.out.println(2);
        // System.out.println(isFound.length);
        return route;
    }
}
