package 每日一题.有序数组的平方;

import java.util.Arrays;

public class Solution {
    //双指针
    public int[] sortedSquares(int[] A) {
        int n = A.length;
        int[] res = new int[n];
        int pos = n - 1;
        for (int i = 0, j = n - 1; i <= j; ) {
            if (A[i] * A[i] > A[j] * A[j]) {
                res[pos] = A[i] * A[i];
                i++;
            } else {
                res[pos] = A[j] * A[j];
                j--;
            }
            pos--;
        }
        return res;
    }

    //直接法
    public int[] sortedSquares_basic(int[] A) {
        int[] res = new int[A.length];
        int k = 0;
        for (int c : A) {
            res[k] = c * c;
            k++;
        }
        Arrays.sort(res);
        return res;
    }
}
