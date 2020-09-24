package 第八章.递归乘法;

public class Solution {
    public int add(int max, int min) {
        if (min == 0)
            return 0;
        if (min == 1)
            return max;
        return max + add(max, --min);
    }

    public int multiply(int A, int B) {
        int max = A > B ? A : B;
        int min = A < B ? A : B;
        return add(max, min);
    }

    //better
    public int mutiply2(int A, int B) {
        if (A > B) return multiply(B, A);
        if (A == 0) return 0;
        return B + multiply(A - 1, B);
    }

    //位运算思路
    public int mutiply3(int A, int B) {
        if (A == 0 || B == 0) return 0;
        if (A < B) return multiply(B, A);
        // int min = Math.min(A, B);
        // int max = Math.max(A, B);
        int ans = 0;
        for (int k = 0; B != 0; k++) {
            if ((B & 1) == 1) {
                ans += A << k;
            }
            B >>= 1;
        }
        return ans;

    }
}
