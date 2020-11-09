package 第八章.合并排序的数组;

import java.util.Arrays;

public class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] total = new int[A.length];
        for (int i = 0; i != n; ++i) {
            A[m + i] = B[i];
        }
        Arrays.sort(A);
    }
}
