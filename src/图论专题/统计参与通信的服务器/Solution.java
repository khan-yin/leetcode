package 图论专题.统计参与通信的服务器;

public class Solution {
    public int l;
    public int w;

    public int countServers(int[][] grid) {
        l = grid.length;
        if (l == 0) return 0;
        w = grid[0].length;
        int[] count_l = new int[l];
        int[] count_w = new int[w];
        int total = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    count_l[i]++;
                    count_w[j]++;
                    total++;
                }
            }
        }
        int noc = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1 && count_l[i] <= 1 && count_w[j] <= 1) {
                    noc++;
                }
            }
        }
        return total - noc;

    }
}
