package 每日一题.有效的山脉数组;

public class Solution {
    //双指针的两种解法
    public boolean validMountainArray(int[] A) {
        if (A.length < 3) {
            return false;
        }
        int i = 0;
        for (i = 0; i < A.length - 1; ) {
            if (A[i] < A[i + 1]) {
                i++;
            } else if (A[i] == A[i + 1]) {
                return false;
            } else {
                if (i == 0)
                    return false;
                for (int j = i; j < A.length - 1; ) {
                    if (A[j] > A[j + 1]) {
                        j++;
                    } else if (A[j] <= A[j + 1]) {
                        return false;
                    }
                }
                return true;
            }
        }
        if (i == A.length - 1)
            return false;
        return true;
    }

    public boolean validMountainArray2(int[] A) {
        if (A.length < 3) {
            return false;
        }
        int i = 0;
        while (i < A.length - 1 && A[i] < A[i + 1])
            i++;
        int j = A.length - 1;
        while (j > 0 && A[j] < A[j - 1])
            j--;
        return i > 0 && j < A.length - 1 && i == j;
    }
}
