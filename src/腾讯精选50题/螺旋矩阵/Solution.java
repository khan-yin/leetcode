package 腾讯精选50题.螺旋矩阵;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<Integer>();
        if(matrix==null||matrix.length==0||matrix[0].length==0)
            return res;
        int row = matrix.length;
        int col=matrix[0].length;
        boolean[][] isvisited= new boolean[row][col];
        int[][] directions = { {0,1},{1,0},{0,-1},{-1,0}};
        int cur = 0;//当前方向
        int cnt=0;
        int i=0;
        int j=0;
        while(cnt<row*col)
        {
            res.add(matrix[i][j]);
            isvisited[i][j]=true;
            int r = i+directions[cur][0];
            int c = j+directions[cur][1];
            cnt++;
            if(r<0||r>=row||c<0||c>=col||isvisited[r][c])
                cur=(cur+1)%4;
            i+=directions[cur][0];
            j+=directions[cur][1];
        }
        return res;
    }
}
