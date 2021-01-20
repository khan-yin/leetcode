package 腾讯精选50题.螺旋矩阵II;

public class Solution {
    public int[][] generateMatrix(int n) {
        int left=0;
        int right=n-1;
        int top=0;
        int bottom=n-1;
        int[][] res = new int[n][n];
        int cnt=1;
        int total=n*n;
        while(cnt<=total)
        {
            for(int i=left;i<=right;i++) res[top][i] = cnt++;
            top++;
            for(int i=top;i<=bottom;i++) res[i][right]=cnt++;
            right--;
            for(int i=right;i>=left;i--) res[bottom][i]=cnt++;
            bottom--;
            for(int i=bottom;i>=top;i--) res[i][left]=cnt++;
            left++;
        }
        return res;
    }
}
