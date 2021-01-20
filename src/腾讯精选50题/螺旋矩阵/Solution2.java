package 腾讯精选50题.螺旋矩阵;

import java.util.ArrayList;
import java.util.List;

public class Solution2 {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<Integer>();
        if(matrix==null||matrix.length==0||matrix[0].length==0)
            return res;
        int row = matrix.length;
        int col=matrix[0].length;
        int left=0;
        int right=col-1;
        int top=0;
        int bottom=row-1;
        int cnt=0;
        int total=row*col;
        while(cnt<total)
        {
            // System.out.println(cnt);
            for(int i=left;i<=right&&cnt<total;i++)
            {
                res.add(matrix[top][i]);
                // System.out.println(matrix[top][i]);
                cnt++;
            }
            top++;
            for(int i=top;i<=bottom&&cnt<total;i++)
            {
                res.add(matrix[i][right]);
                cnt++;
            }
            right--;
            for(int i=right;i>=left&&cnt<total;i--)
            {
                res.add(matrix[bottom][i]);
                cnt++;
            }
            bottom--;
            for(int i=bottom;i>=top&&cnt<total;i--)
            {
                res.add(matrix[i][left]);
                cnt++;
            }
            left++;
        }
        return res;
    }
}
