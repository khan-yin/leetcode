package 第五章.三步问题;

public class Solution {
    public long[] dp = new long[1000000];

    public int waysToStep2(int n) {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++) {
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000007;
        }

        return (int) dp[n];
    }

    //递归超时
    public int waysToStep(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else if (n == 3)
            return 4;
        else
            return waysToStep(n - 3) % 1000000007 + waysToStep(n - 2) % 1000000007 + waysToStep(n - 1) % 1000000007;
    }

}
