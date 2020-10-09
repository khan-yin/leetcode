package 第八章.颜色填充;

public class Solution2 {
    //改良版
    public int column = 0;
    public int line = 0;
    public int oldColor;

    public void dfs(int[][] image, int sr, int sc, int newColor) {
        //越界
        if (sr == -1 || sr == line || sc == -1 || sc == column)
            return;
        //没有越界则递归
        if (image[sr][sc] == this.oldColor && image[sr][sc] != newColor) {
            image[sr][sc] = newColor;
            //左
            dfs(image, sr, sc - 1, newColor);
            //右
            dfs(image, sr, sc + 1, newColor);
            //上
            dfs(image, sr - 1, sc, newColor);
            //下
            dfs(image, sr + 1, sc, newColor);
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        this.oldColor = image[sr][sc];
        this.line = image.length;
        if (line == 0)
            return image;
        this.column = image[0].length;
        dfs(image, sr, sc, newColor);
        return image;
    }
}
