package 图论专题.找到小镇的法官;

public class Solution {
    public int findJudge(int N, int[][] trust) {
        int[] enter = new int[N + 1];//入度
        int[] out = new int[N + 1];//出度
        for (int[] lis : trust) {
            int a = lis[0];
            int b = lis[1];
            enter[b]++;
            out[a]++;
        }
        for (int i = 1; i <= N; i++) {
            if (enter[i] == N - 1 && out[i] == 0)
                return i;
        }
        return -1;
    }
}
