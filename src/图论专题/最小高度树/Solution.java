package 图论专题.最小高度树;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList();
        List<List<Integer>> graph = new ArrayList();
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<Integer>());
        int[] enter = new int[n];
        if (n == 0)
            return res;
        else if (n == 1) {
            res.add(0);
            return res;
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
            enter[edge[0]]++;
            enter[edge[1]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (enter[i] == 1)
                queue.offer(i);
        }

        while (!queue.isEmpty()) {
            res = new ArrayList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Integer t = queue.remove();
                res.add(t);
                for (int node : graph.get(t)) {
                    enter[node]--;
                    if (enter[node] == 1)
                        queue.add(node);
                }
            }

        }
        return res;
    }
}
