package 图论专题.最大网络秩;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int count(int one, int two, List<List<Integer>> nodelist) {
        int l1 = nodelist.get(one).size();
        int l2 = nodelist.get(two).size();
        if (nodelist.get(one).contains(two))
            l1--;
        return l1 + l2;
    }

    public int maximalNetworkRank(int n, int[][] roads) {
        List<List<Integer>> nodelist = new ArrayList();
        for (int i = 0; i < n; i++) {
            nodelist.add(new ArrayList<Integer>());
        }
        for (int[] road : roads) {
            nodelist.get(road[0]).add(road[1]);
            nodelist.get(road[1]).add(road[0]);
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int c = count(i, j, nodelist);
                max = c > max ? c : max;
                // System.out.println(c);
            }
        }
        return max;
    }
}
