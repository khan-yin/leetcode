package 第一章.旋转矩阵;

import java.util.Arrays;

public class Solution {
    public static void main(String[] args) {

        Solution solution=new Solution();
        int[][] ns = {
                { 1,2,3 },
                { 4,5,6 },
                { 7,8,9 }
        };

        int[][] ns2 =            {
                { 5, 1, 9,11},
                { 2, 4, 8,10},
                {13, 3, 6, 7},
                {15,14,12,16}
        };

//        System.out.println(Arrays.deepToString(ns));
        solution.rotate(ns);
        solution.rotate(ns2);
        System.out.println(Arrays.deepToString(ns));
        System.out.println(Arrays.deepToString(ns2));
    }

    public void rotate(int[][] matrix) {
        //主对角线旋转然后互换行
        int len=matrix.length;
        int t;
        int i;
        int j;
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
//        System.out.println(Arrays.deepToString(matrix));
        for(i=0;i<len;i++)
        {
            for(j=0;j<len/2;j++)
            {
                t=matrix[i][j];
                matrix[i][j]=matrix[i][len-1-j];
                matrix[i][len-1-j]=t;
            }
        }
//        System.out.println(Arrays.deepToString(matrix));
    }
}
