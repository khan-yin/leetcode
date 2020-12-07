package 图论专题.翻转矩阵后的得分;

public class Solution {
    public int matrixScore(int[][] A) {
        int l = A.length;
        int w = A[0].length;
        int res = l * (1 << (w - 1));
        for (int j = 1; j < w; j++)//列
        {
            int OnteCnt = 0;//记录这一列的1的个数
            for (int i = 0; i < l; i++)//行
            {
                if (A[i][0] == 1) {
                    OnteCnt += A[i][j];//直接加，如果为1则++如果为0则不会变
                } else
                    OnteCnt += 1 - A[i][j];//对于行不为1的是需要反转的，所以相应的行元素需要取反
            }
            int n = Math.max(OnteCnt, l - OnteCnt);
            res += n * (1 << (w - j - 1));
        }
        return res;
    }
}
