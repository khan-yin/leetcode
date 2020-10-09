package 第八章.颜色填充;

public class Solution {
    public int column = 0;
    public int line = 0;
    public int[][] image;
    public boolean[][] isvisited;
    public int oldColor;

    public void dfs(int sr, int sc, int newColor) {
        //越界

        if (sr == -1 || sr == line || sc == -1 || sc == column || isvisited[sr][sc])
            return;

        System.out.println(sr + " " + sc);
        //标记访问节点
        isvisited[sr][sc] = true;
        //没有越界则递归
        if (image[sr][sc] == this.oldColor) {
            image[sr][sc] = newColor;
            //左
            dfs(sr, sc - 1, newColor);
            //右
            dfs(sr, sc + 1, newColor);
            //上
            dfs(sr - 1, sc, newColor);
            //下
            dfs(sr + 1, sc, newColor);
        }


    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        this.oldColor = image[sr][sc];
        this.line = image.length;
        if (line == 0)
            return image;
        this.column = image[0].length;
        this.image = new int[line][column];
        this.image = image;
        this.isvisited = new boolean[line][column];
        dfs(sr, sc, newColor);
        return this.image;
    }
}
