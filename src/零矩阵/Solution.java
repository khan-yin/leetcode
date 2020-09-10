package 零矩阵;

import javax.management.MBeanAttributeInfo;
import java.util.Arrays;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] matrix={
                {1,1,1},
                {1,0,1},
                {1,1,1}
            };

        int[][] mat={
                {0,1,2,0},
                {3,4,5,2},
                {1,3,1,5}
            };
        solution.setZeroes(mat);
        System.out.println(Arrays.deepToString(mat));
    }

    public void setZeroes(int[][] matrix) {
        /**
         * 需要设零的行i：将该行的第一列元素matrix[i][0]设为0，表示该行需要清零；
         * 需要设为零的列j：将该列的第一行元素matrix[0][j]设为0，表示该列需要清零；
         * 根据第一行和第一列的标记，进行清零操作。
         * matrix[0][0]即表示第一行又表示第一列,需要特殊处理
         *
         * 参考题解来源：
         * 作者：SHINE4YG
         * 链接：https://leetcode-cn.com/problems/zero-matrix-lcci/solution/jiang-xing-lie-xin-xi-cun-fang-zai-yuan-shu-zu-de-/
         * 来源：力扣（LeetCode）
         * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
         */
        int m=matrix.length;
        int n=matrix[0].length;
        boolean x0=false;
        boolean y0=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0)
                    {
                        //说明第0行需要清零
                        x0=true;
                    }
                    if(j==0)
                    {
                        //说明第0列需要清零
                        y0=true;
                    }
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }


        for(int j=1;j<m;j++)
        {
            if(matrix[j][0]==0)
            {
                for(int i=0;i<n;i++)
                {
                    matrix[j][i]=0;
                }
            }
        }

        for(int j=1;j<n;j++)
        {
            if(matrix[0][j]==0)
            {
                for(int i=0;i<m;i++)
                {
                    matrix[i][j]=0;
                }
            }
        }

        if(x0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }

        if(y0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
}
