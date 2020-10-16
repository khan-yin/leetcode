package 第八章.硬币;

public class Solution {
    static final int MOD = 1000000007;
    int[] coins = {25, 10, 5, 1};

    public int waysToChange(int n) {
        int[] waylist = new int[n + 1];
        waylist[0] = 1;
        for (int i = 0; i < 4; i++) {
            int coin = coins[i];
            for (int j = coin; j <= n; j++) {
                waylist[j] = (waylist[j] + waylist[j - coin]) % MOD;
            }
        }
        return waylist[n];
    }
}
