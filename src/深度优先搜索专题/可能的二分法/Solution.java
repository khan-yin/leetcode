package 深度优先搜索专题.可能的二分法;

import java.util.ArrayList;
import java.util.HashMap;

public class Solution {
    public ArrayList<Integer>[] graph;
    public HashMap<Integer, Integer> node_color = new HashMap<>();

    public boolean dfs(int node, int color) {
        if (node_color.containsKey(node))
            return node_color.get(node) == color;
        node_color.put(node, color);

        for (int other : graph[node])//找该node讨厌的节点
            if (!dfs(other, color ^ 1))//涂色取反
                return false;
        return true;
    }

    public boolean possibleBipartition(int N, int[][] dislikes) {
        graph = new ArrayList[N + 1];//1-n节点
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList();

        for (int[] edge : dislikes) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        for (int i = 1; i <= N; i++) {
            if (!node_color.containsKey(i))//节点还没着色
            {
                boolean isright = dfs(i, 0);
                if (!isright)
                    return isright;
            }
        }
        return true;
    }
}
