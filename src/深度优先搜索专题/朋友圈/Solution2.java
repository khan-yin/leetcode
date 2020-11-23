package 深度优先搜索专题.朋友圈;

public class Solution2 {
    public boolean[] isvisited;

    public void dfs(int[][] M, boolean[] isvisited, int index) {
        int n = M.length;
        if (isvisited[index])
            return;

        isvisited[index] = true;
        for (int i = 0; i < n; i++) {
            if (M[index][i] == 1 && index != i) {
                dfs(M, isvisited, i);
            }
        }
    }

    public int findCircleNum(int[][] M) {
        int n = M.length;
        if (n == 0 || n == 1)
            return n;
        isvisited = new boolean[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!isvisited[i]) {
                dfs(M, isvisited, i);
                cnt++;
            }
        }
        return cnt;
    }
}
