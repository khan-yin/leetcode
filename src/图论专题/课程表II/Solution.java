package 图论专题.课程表II;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    //拓扑排序经典题目，bfs操作更好
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        HashMap<Integer, ArrayList<Integer>> nodemaplist = new HashMap<>();
        if (numCourses <= 1)
            return true;

        int[] enter = new int[numCourses];//入度
        int[] to = new int[numCourses];//出度
        for (int[] courserelation : prerequisites) {
            int target = courserelation[0];
            int pre = courserelation[1];
            enter[target]++;
            to[pre]++;
            if (!nodemaplist.containsKey(pre))//对先驱节点创建邻接表
                nodemaplist.put(pre, new ArrayList<Integer>());
            nodemaplist.get(pre).add(target);
        }
        Queue<Integer> queue = new LinkedList<>();//用队列来维护bfs遍历
        int cnt = 0;//记录访问的节点数
        for (int i = 0; i < enter.length; i++) {
            if (enter[i] == 0)
                queue.offer(i);//初始化队列，将queue加入其中
        }

        while (!queue.isEmpty()) {
            int temp = queue.remove();
            cnt++;
            if (to[temp] == 0)//出度为0则无需遍历
                continue;
            for (int target : nodemaplist.get(temp)) {
                enter[target]--;
                if (enter[target] == 0)
                    queue.offer(target);
            }
        }
        return cnt == numCourses;
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        HashMap<Integer, ArrayList<Integer>> nodemaplist = new HashMap<>();
        int[] res = new int[numCourses];
        if (numCourses == 0)//特判
            return res;
        else if (numCourses == 1) {
            res[0] = 0;
            return res;
        }

        int[] enter = new int[numCourses];//入度
        int[] to = new int[numCourses];//出度
        for (int[] courserelation : prerequisites) {
            int target = courserelation[0];
            int pre = courserelation[1];
            enter[target]++;
            to[pre]++;
            if (!nodemaplist.containsKey(pre))//对先驱节点创建邻接表
                nodemaplist.put(pre, new ArrayList<Integer>());
            nodemaplist.get(pre).add(target);
        }
        Queue<Integer> queue = new LinkedList<>();//用队列来维护bfs遍历
        int cnt = 0;//记录访问的节点数
        for (int i = 0; i < enter.length; i++) {
            if (enter[i] == 0)
                queue.offer(i);//初始化队列，将queue加入其中
        }

        while (!queue.isEmpty()) {
            int temp = queue.remove();
            res[cnt++] = temp;
            if (to[temp] == 0)//出度为0则无需遍历
                continue;
            for (int target : nodemaplist.get(temp)) {
                enter[target]--;
                if (enter[target] == 0)
                    queue.offer(target);
            }
        }
        if (cnt < numCourses)//cnt比numCousers小则遍历不完全，一定存在环
            return new int[0];
        else
            return res;
    }
}
