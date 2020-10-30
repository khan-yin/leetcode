package 第16章.最小差;

import java.util.Arrays;

public class Solution {
    public int smallestDifference(int[] a, int[] b) {
        //排序，归并双指针法
        Arrays.sort(a);
        Arrays.sort(b);
        long min = Integer.MAX_VALUE;
        for (int i = 0, j = 0; i < a.length && j < b.length; ) {
            min = Math.min(min, Math.abs((long) a[i] - (long) b[j]));
            // System.out.println(a[i]+" "+b[j]);
            if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        return (int) min;
    }

    //超时
    public int badway(int[] a, int b[]) {
        long min = a[0] > b[0] ? ((long) a[0] - (long) b[0]) : ((long) b[0] - (long) a[0]);
        System.out.println(min);
        for (long i : a) {
            for (long j : b) {
                // System.out.println(Math.abs(i-j));
                min = min > Math.abs(i - j) ? Math.abs(i - j) : min;
            }
        }
        return (int) min;
    }
}
