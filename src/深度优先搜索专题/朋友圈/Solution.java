package 深度优先搜索专题.朋友圈;

import java.util.HashSet;
import java.util.Set;

public class Solution {
    //并查集方法，遍历矩阵复杂度太高
    public int findCircleNum(int[][] M) {
        int n = M.length;
        if (n == 0 || n == 1)
            return n;
        int[] friends = new int[n];
        for (int i = 0; i < n; i++)
            friends[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1 && i != j)
                    union(friends, i, j);
            }
        }

        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            if (friends[i] == i)
                set.add(friends[i]);
        }
        return set.size();
    }

    public int find(int[] friends, int i) {
        return (friends[i] == i) ? i : find(friends, friends[i]);
    }

    void union(int friends[], int x, int y) {
        int xset = find(friends, x);
        int yset = find(friends, y);
        if (xset != yset)
            friends[xset] = yset;
    }
}
