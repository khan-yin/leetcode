package 剑指offer.数值的整数次方;

public class Solution {
    public double myPow(double x, int n) {
        if (x == 0) return 0;
        long b = n;
        double a = x * 1.0;
        if (n < 0) {
            b = -b;
            a = 1 / a;
        }
        double res = 1;
        while (b > 0) {
            if ((b & 1) == 1)//末位为1
                res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
}
