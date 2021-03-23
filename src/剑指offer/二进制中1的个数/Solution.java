package 剑指offer.二进制中1的个数;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println("Hello World!");
        System.out.println(solution.hammingWeight2(00000000000000000000000000001011));
    }

    public int hammingWeight2(int n) {
        int res = 0;
        while (n != 0) {
            res++;
            n &= n - 1;
        }
        return res;
    }

    public int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            res += n & 1;
            n >>>= 1;//无符号的位移
        }
        return res;
    }
}
