package 剑指offer.打印从1到最大的n位数;

public class Solution {
    int[] res;
    int count = 0;

    public void dfs(int now, char[] number, int length) {
        if (now == length) {
            res[count++] = Integer.parseInt(String.valueOf(number));
            return;
        } else {
            for (char i = '0'; i <= '9'; i++) {
                number[now] = i;
                dfs(now + 1, number, length);
            }
        }
    }

    public int[] printNumbers(int n) {
        res = new int[(int) Math.pow(10, n) - 1];
        for (int len = 1; len <= n; len++) {
            for (char first = '1'; first <= '9'; first++) {
                char[] number = new char[len];
                number[0] = first;
                dfs(1, number, len);
            }
        }
        return res;
    }
}
