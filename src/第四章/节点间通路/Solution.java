package 第四章.节点间通路;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Solution {
    public boolean findWhetherExistsPath(int n, int[][] graph, int start, int target) {
        List<Integer>[] adj = new ArrayList[n];
        for (int[] edge : graph) {
            int from = edge[0];
            int to = edge[1];
            if (adj[from] == null) {
                adj[from] = new ArrayList<>();
            }
            adj[from].add(to);
        }

        //bfs
        LinkedList<Integer> q = new LinkedList<>();
        boolean[] isFind = new boolean[n];
        q.offer(start);
        isFind[start] = true;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.poll();
                List<Integer> nodelist = adj[node];
                if (nodelist == null) {
                    continue;
                }
                if (nodelist.isEmpty()) {
                    continue;
                } else {
                    for (Integer k : nodelist) {
                        if (k == target) {
                            return true;
                        }
                        if (isFind[k] == true) {
                            continue;
                        }
                        q.offer(k);
                        isFind[k] = true;
                    }
                }


            }
        }
        return false;


    }
}
