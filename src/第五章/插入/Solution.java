package 第五章.插入;

public class Solution {
    public int insertBits(int N, int M, int i, int j) {
        // long n= (long) N;
        // long m= (long) M;
        // int d=j-i;
        // m=m<<i;
        int n = ~((-1 >>> (31 - j)) & (-1 << i));
        N = N & n;
        M = M << i;
        N = M | N;
        return N;
    }
}
